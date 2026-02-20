# Compiler and flags (Arch Linux optimized)
CXX = g++
CC = gcc
CXXFLAGS = -Wall -Wextra -std=c++17 -O3 -march=native -mtune=native
CFLAGS = -Wall -Wextra -O3 -march=native -mtune=native
AR = ar
ARFLAGS = rcs

# Directories
SRC_DIR = src
LIB_DIR = lib
BUILD_DIR = build

# Files
CPP_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
H_FILES = $(wildcard $(SRC_DIR)/*.h)
OBJECTS = $(CPP_SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
LIBRARY = $(LIB_DIR)/libHiCPPM.a
HEADER = $(LIB_DIR)/HiCPPM.h

# Targets
BENCHMARK = main
BENCHMARK_SRC = benchmark.cpp

# Default target
all: $(LIBRARY)

# Create combined header (extracth.sh)
$(HEADER): $(H_FILES) | $(LIB_DIR)
	@echo "→ Copying header files..."
	@for file in $(H_FILES); do \
		echo "// $$file" >> $(HEADER); \
		cat "$$file" >> $(HEADER); \
		echo "" >> $(HEADER); \
	done
	@echo "✓ Combined header created: $(HEADER)"

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo "→ Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Create library (makelib.sh)
$(LIBRARY): $(HEADER) $(OBJECTS) | $(LIB_DIR)
	@echo "→ Creating library..."
	@$(AR) $(ARFLAGS) $@ $(OBJECTS)
	@echo "✓ Library created: $(LIBRARY)"

# Build benchmark (runbenchmark.sh - part 1)
$(BENCHMARK): $(LIBRARY) $(BENCHMARK_SRC)
	@echo "→ Building benchmark..."
	@$(CXX) $(CXXFLAGS) $(BENCHMARK_SRC) $(LIBRARY) -o $@
	@echo "✓ Benchmark built: $(BENCHMARK)"

# Run benchmark (runbenchmark.sh - full)
benchmark: $(BENCHMARK)
	@echo "→ Running benchmark..."
	@./$(BENCHMARK)

# Run with perf (Arch-specific)
perf: $(BENCHMARK)
	@echo "→ Running with perf..."
	@perf stat -d ./$(BENCHMARK)

# Generate flame graph (requires perf and flamegraph)
flamegraph: $(BENCHMARK)
	@echo "→ Generating flame graph..."
	@perf record -F 99 -g ./$(BENCHMARK)
	@perf script | stackcollapse-perf.pl | flamegraph.pl > flamegraph.svg
	@echo "✓ Flame graph: flamegraph.svg"

# Create directories
$(BUILD_DIR) $(LIB_DIR):
	@mkdir -p $@

# Clean (cleanup.sh)
clean:
	@echo "→ Cleaning..."
	@rm -f $(BENCHMARK)
	@rm -rf $(LIB_DIR) $(BUILD_DIR)
	@rm -f perf.data perf.data.old flamegraph.svg
	@echo "✓ Cleaned"

# Rebuild everything
rebuild: clean all

# Extract header only
extracth: $(HEADER)

# Make library only
makelib: $(LIBRARY)

# Install to system (optional)
install: $(LIBRARY) $(HEADER)
	@echo "→ Installing library..."
	@sudo install -Dm644 $(LIBRARY) /usr/local/lib/libHiCPPM.a
	@sudo install -Dm644 $(HEADER) /usr/local/include/HiCPPM.h
	@echo "✓ Library installed to /usr/local"

# Uninstall from system
uninstall:
	@echo "→ Uninstalling library..."
	@sudo rm -f /usr/local/lib/libHiCPPM.a
	@sudo rm -f /usr/local/include/HiCPPM.h
	@echo "✓ Library uninstalled"

# Create PKGBUILD for AUR (Arch packaging)
pkgbuild:
	@echo "→ Creating PKGBUILD..."
	@echo "# Maintainer: Your Name <your.email@example.com>" > PKGBUILD
	@echo "pkgname=hicppm" >> PKGBUILD
	@echo "pkgver=1.0.0" >> PKGBUILD
	@echo "pkgrel=1" >> PKGBUILD
	@echo "pkgdesc=\"High-performance C++ math library\"" >> PKGBUILD
	@echo "arch=('x86_64')" >> PKGBUILD
	@echo "url=\"https://github.com/Awaboi-Codes/HiCPPM"" >> PKGBUILD
	@echo "license=('MIT')" >> PKGBUILD
	@echo "depends=()" >> PKGBUILD
	@echo "makedepends=('gcc' 'make')" >> PKGBUILD
	@echo "" >> PKGBUILD
	@echo "build() {" >> PKGBUILD
	@echo "  cd \"\$$srcdir\"" >> PKGBUILD
	@echo "  make" >> PKGBUILD
	@echo "}" >> PKGBUILD
	@echo "" >> PKGBUILD
	@echo "package() {" >> PKGBUILD
	@echo "  cd \"\$$srcdir\"" >> PKGBUILD
	@echo "  install -Dm644 lib/libHiCPPM.a \"\$$pkgdir/usr/lib/libHiCPPM.a\"" >> PKGBUILD
	@echo "  install -Dm644 lib/HiCPPM.h \"\$$pkgdir/usr/include/HiCPPM.h\"" >> PKGBUILD
	@echo "}" >> PKGBUILD
	@echo "✓ PKGBUILD created"

# Show build info
info:
	@echo "Build Configuration:"
	@echo "  Compiler:   $(CXX)"
	@echo "  C Flags:    $(CFLAGS)"
	@echo "  CXX Flags:  $(CXXFLAGS)"
	@echo "  Sources:    $(CPP_SOURCES)"
	@echo "  Objects:    $(OBJECTS)"
	@echo "  Library:    $(LIBRARY)"
	@echo "  Header:     $(HEADER)"

# Help
help:
	@echo "Available targets:"
	@echo "  all        - Build library and header (default)"
	@echo "  benchmark  - Build and run benchmark"
	@echo "  perf       - Run benchmark with perf profiling"
	@echo "  flamegraph - Generate performance flame graph"
	@echo "  makelib    - Build library only"
	@echo "  extracth   - Extract combined header only"
	@echo "  install    - Install library system-wide"
	@echo "  uninstall  - Remove installed library"
	@echo "  pkgbuild   - Create PKGBUILD for Arch packaging"
	@echo "  clean      - Remove all build files"
	@echo "  rebuild    - Clean and rebuild"
	@echo "  info       - Show build configuration"
	@echo "  help       - Show this help"

.PHONY: all benchmark perf flamegraph makelib extracth install uninstall pkgbuild clean rebuild info help