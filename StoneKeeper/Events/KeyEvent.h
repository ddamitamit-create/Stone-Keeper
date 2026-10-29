#pragma once

#include <format>
#include "Event.h"

namespace StoneKeeper {
    class ENGINE_API KeyEvent : public Event {
    public:
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keyCode)
            : m_KeyCode(keyCode) {}

        int m_KeyCode;
    };

    class ENGINE_API KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, bool isRepeating)
            : KeyEvent(keycode), m_IsRepeating(isRepeating) {}

        [[nodiscard]] inline bool IsRepeating() const { return m_IsRepeating; }

        [[nodiscard]] std::string ToString() const override {
            return std::format("KeyPressedEvent: {} (repeating: {})", m_KeyCode, m_IsRepeating);
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        bool m_IsRepeating;
    };

    class ENGINE_API KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keycode)
                : KeyEvent(keycode) {}


            [[nodiscard]] std::string ToString() const override {
                return std::format("KeyReleasedEvent: {}", m_KeyCode);
            }

            EVENT_CLASS_TYPE(KeyReleased)
        };
}