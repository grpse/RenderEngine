#include "Input.h"

Input* Input::m_instance = new Input();

Point Input::getPointer() {
    return Input::m_instance->m_pointers[0];
}

Point* Input::getPointers() {
    return Input::m_instance->m_pointers;
}

bool Input::leftButtonPressed() {
    return Input::m_instance->m_leftWasPressed;
}

bool Input::rightButtonPressed() {
    return Input::m_instance->m_rightWasPressed;
}

void Input::clearLastInputs() {
    (*Input::m_instance) = {};
}
