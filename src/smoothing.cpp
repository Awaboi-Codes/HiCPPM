#include "smoothing.h"
#include "alegebraic.h"

#include <cmath>

class lerp {
    // why is lerp basically a PID Controller XD
    private:
        double position = 0;
        double target = 0;
        double step = 0.1;
        double error = 0;
        LerpType type;

    public:
        lerp(LerpType lerpType = LINEAR) {
            this -> type = lerpType;
        }

        void interpolate() {
            error = abs(position-target);
            switch (this -> type) {
                case LINEAR:
                    position += error * step;
                    break;
                case EXPONENTIAL:
                    position += (error * step) * (error * step);
                    break;
                case SQUARE:
                    position += squareRoot(error, 5);
                    break;
            }
        }

        void setTarget(double target) {
            this -> target = target;
        }

        void setStep(double step) {
            this -> step = step;
        }

        void setPosition(double pos) {
            this -> position = pos;
        }
};