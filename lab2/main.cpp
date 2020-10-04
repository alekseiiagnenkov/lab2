#include "Astroid.h"

using namespace Prog2;
const char* msgs[] = { " [0] Exit",
                      " [1] Input inner circle radius",
                      " [2] Input \"t\" and get curve length",
                      " [3] Get curve length",
                      " [4] Input \"t\" and get radius of curvature",
                      " [5] Get Area",
                      " [6] Input \"t\" and get (x, y)",
                      " [7] Input \"X\" and get Y"
};

const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int (*functions[])(Astroid&) = { nullptr, dialog_input, dialog_getCurveLength_t,
                                 dialog_getCurveLength, dialog_getRadCur, dialog_getArea,
                                 dialog_getXY, dialog_getY };


int main() {
    Astroid A;
    int rc;
    while ((rc = dialog(msgs, NMsgs))) {
        if (!functions[rc](A))
            break;
    }
}