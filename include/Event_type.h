#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H
#include <cstdint>
#include <stdexcept>
class Terminate_program : public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Program is forced to be terminated by user";
        }
};
typedef unsigned int Uint32;
typedef uint8_t Uint8;
typedef int Sint32;
typedef unsigned short Uint16;
typedef int16_t Sint16;
typedef struct SDL_CommonEvent
{
    Uint32 type;
    Uint32 timestamp;
} SDL_CommonEvent;
typedef struct SDL_WindowEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    Uint8 event;
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint32 data1;
    Sint32 data2;
} SDL_WindowEvent;

typedef enum {
    SDL_SCANCODE_UNKNOWN = 0,
    SDL_SCANCODE_A = 4,
    SDL_SCANCODE_B = 5,
} SDL_Scancode;
typedef int SDL_Keycode;
typedef struct SDL_Keysym {
    SDL_Scancode scancode;  
    SDL_Keycode sym;        
    Uint16 mod;             
    Uint32 unused;          
} SDL_Keysym;

typedef struct SDL_KeyboardEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    Uint32 state;
    Uint32 repeat;
    SDL_Keysym keysym;
} SDL_KeyboardEvent;

typedef struct SDL_TextEditingEvent {
    Uint32 type;             
    Uint32 timestamp;        
    Uint32 windowID;        
    char text[32]; 
    Sint32 start;            
    Sint32 length;          
} SDL_TextEditingEvent;

typedef struct SDL_TextInputEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    char text[32];
} SDL_TextInputEvent;

typedef struct SDL_MouseMotionEvent {
    Uint32 type;        /**< The event type, set to SDL_MOUSEMOTION. */
    Uint32 timestamp;   /**< The timestamp of the event. */
    Uint32 windowID;    /**< The window with mouse focus, if any. */
    Uint32 which;       /**< The mouse instance id, or SDL_TOUCH_MOUSEID. */
    Uint32 state;       /**< The current button state. */
    Sint32 x;           /**< X coordinate, relative to window. */
    Sint32 y;           /**< Y coordinate, relative to window. */
    Sint32 xrel;        /**< The relative motion in the X direction. */
    Sint32 yrel;        /**< The relative motion in the Y direction. */
} SDL_MouseMotionEvent;

typedef struct SDL_MouseButtonEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    Uint32 which;
    Uint8 button;
    Uint8 state;
    Uint8 clicks;
    Sint32 x;
    Sint32 y;
} SDL_MouseButtonEvent;

typedef struct SDL_MouseWheelEvent {
    Uint32 type;        /**< Event type, should be SDL_MOUSEWHEEL */
    Uint32 timestamp;   /**< Timestamp of the event */
    Uint32 windowID;    /**< The window with mouse focus, if any */
    Uint32 which;       /**< The mouse instance id, or SDL_TOUCH_MOUSEID */
    Sint32 x;           /**< The amount scrolled horizontally */
    Sint32 y;           /**< The amount scrolled vertically */
    Uint32 direction;   /**< Set to one of the SDL_MOUSEWHEEL_* macros */
} SDL_MouseWheelEvent;

typedef Sint32 SDL_JoystickID;
typedef struct SDL_JoyAxisEvent {
    Uint32 type;         /**< SDL_JOYAXISMOTION */
    Uint32 timestamp;    /**< In milliseconds, populated using SDL_GetTicks() */
    SDL_JoystickID which; /**< The joystick instance id */
    Uint8 axis;          /**< The joystick axis index */
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint16 value;        /**< The axis value (range: -32768 to 32767) */
    Uint16 padding4;
} SDL_JoyAxisEvent;

typedef struct SDL_JoyBallEvent {
    Uint32 type;        /**< SDL_JOYBALLMOTION */
    Uint32 timestamp;   /**< In milliseconds, populated using SDL_GetTicks() */
    SDL_JoystickID which; /**< The joystick instance id */
    Uint8 ball;         /**< The joystick trackball index */
    Sint16 xrel;        /**< The relative motion in the X direction */
    Sint16 yrel;        /**< The relative motion in the Y direction */
} SDL_JoyBallEvent;

typedef struct SDL_JoyHatEvent {
    Uint32 type;
    Uint32 timestamp;
    SDL_JoystickID which;
    Uint8 hat;
    Uint8 value;
} SDL_JoyHatEvent;

typedef struct SDL_JoyButtonEvent {
    Uint32 type;        /**< SDL_JOYBUTTONDOWN or SDL_JOYBUTTONUP */
    Uint32 timestamp;   /**< Timestamp of the event */
    SDL_JoystickID which; /**< The joystick instance id */
    Uint8 button;       /**< The joystick button index */
    Uint8 state;        /**< SDL_PRESSED or SDL_RELEASED */
    Uint8 padding1;
    Uint8 padding2;
} SDL_JoyButtonEvent;

typedef struct SDL_ControllerAxisEvent
{
    Uint32 type;        /**< SDL_CONTROLLERAXISMOTION */
    Uint32 timestamp;   /**< In milliseconds, populated using SDL_GetTicks() */
    Sint32 which;       /**< The joystick instance id */
    Uint8 axis;         /**< The controller axis (SDL_GameControllerAxis) */
    Uint8 padding1;
    Uint8 padding2;
    Uint8 padding3;
    Sint16 value;       /**< The axis value (range: -32768 to 32767) */
    Uint16 padding4;
} SDL_ControllerAxisEvent;

typedef struct SDL_ControllerButtonEvent
{
    Uint32 type;
    Uint32 timestamp;
    SDL_JoystickID which;
    Uint8 button;
    Uint8 state;
    Uint8 padding1;
    Uint8 padding2;
} SDL_ControllerButtonEvent;

typedef struct SDL_ControllerDeviceEvent {
    Uint32 type;        /**< SDL_CONTROLLERDEVICEADDED or SDL_CONTROLLERDEVICEREMOVED */
    Uint32 timestamp;   /**< timestamp of the event */
    Sint32 which;       /**< the joystick device index for the ADDED event, or the instance id for the REMOVED event */
} SDL_ControllerDeviceEvent;

typedef struct SDL_AudioDeviceEvent {
    uint32_t type;        // SDL_AUDIODEVICEADDED or SDL_AUDIODEVICEREMOVED
    uint32_t timestamp;
    uint32_t which;       // index of the audio device (starts at 1)
    uint8_t iscapture;    // non-zero if this is a capture device
    uint8_t padding1;
    uint8_t padding2;
    uint8_t padding3;
} SDL_AudioDeviceEvent;

// typedef struct SDL_CommonEvent {
//     Uint32 type;
//     Uint32 timestamp;
// } SDL_CommonEvent;

typedef struct SDL_QuitEvent {
    Uint32 type;
    SDL_CommonEvent common;
} SDL_QuitEvent;

typedef struct SDL_UserEvent {
    Uint32 type;
    Uint32 timestamp;
    Uint32 windowID;
    Sint32 code;
    void* data1;
    void* data2;
} SDL_UserEvent;

typedef struct SDL_SysWMEvent {
    Uint32 type;
    void* msg;
} SDL_SysWMEvent;

typedef Uint32 SDL_TouchID;
typedef Uint32 SDL_FingerID;
typedef struct SDL_TouchFingerEvent {
    Uint32 type;        /**< ::SDL_FINGERMOTION or ::SDL_FINGERDOWN or ::SDL_FINGERUP */
    Uint32 timestamp;
    SDL_TouchID touchId;
    SDL_FingerID fingerId;
    float x;
    float y;
    float dx;
    float dy;
    float pressure;
} SDL_TouchFingerEvent;

typedef struct SDL_MultiGestureEvent
{
    Uint32 type;        /**< SDL_MULTIGESTURE */
    Uint32 timestamp;   /**< timestamp for when the event occurred */
    SDL_TouchID touchId;/**< The touch device index */
    float dTheta;       /**< relative angle change of the gesture */
    float dDist;        /**< relative distance change of the gesture */
    float x;            /**< initial center position of the first touch */
    float y;            /**< initial center position of the first touch */
    Uint16 numFingers;  /**< number of fingers used in the gesture */
    Uint16 padding;     /**< for binary compatibility */
} SDL_MultiGestureEvent;

typedef uint32_t SDL_GestureID;
typedef struct SDL_DollarGestureEvent {
    Uint32 type;         /**< SDL_DOLLARGESTURE or SDL_DOLLARRECORD */
    SDL_TouchID touchId; /**< The touch device id */
    SDL_GestureID gestureId; /**< The unique id of the gesture */
    Uint32 numFingers;   /**< Number of fingers used */
    float error;         /**< The error margin of the gesture */
    float x;             /**< Normalized center of gesture */
    float y;             /**< Normalized center of gesture */
} SDL_DollarGestureEvent;

typedef struct SDL_DropEvent
{
    Uint32 type;
    Uint32 timestamp;
    char *file;
} SDL_DropEvent;

typedef union SDL_Event {
    Uint32 type;        /**< Event type, shared with all events */
    SDL_CommonEvent common;  /**< Common event data */
    SDL_WindowEvent window;  /**< Window event data */
    SDL_KeyboardEvent key;   /**< Keyboard event data */
    SDL_TextEditingEvent edit;  /**< Text editing event data */
    SDL_TextInputEvent text;    /**< Text input event data */
    SDL_MouseMotionEvent motion;  /**< Mouse motion event data */
    SDL_MouseButtonEvent button;  /**< Mouse button event data */
    SDL_MouseWheelEvent wheel;    /**< Mouse wheel event data */
    SDL_JoyAxisEvent jaxis;   /**< Joystick axis event data */
    SDL_JoyBallEvent jball;   /**< Joystick ball event data */
    SDL_JoyHatEvent jhat;     /**< Joystick hat event data */
    SDL_JoyButtonEvent jbutton;  /**< Joystick button event data */
    SDL_ControllerAxisEvent caxis;  /**< Game controller axis event data */
    SDL_ControllerButtonEvent cbutton;  /**< Game controller button event data */
    SDL_ControllerDeviceEvent cdevice;  /**< Game controller device event data */
    SDL_AudioDeviceEvent adevice; /**< Audio device event data */
    SDL_QuitEvent quit;   /**< Quit request event data */
    SDL_UserEvent user;   /**< Custom event data */
    SDL_SysWMEvent syswm; /**< System dependent window event data */
    SDL_TouchFingerEvent tfinger;   /**< Touch finger event data */
    SDL_MultiGestureEvent mgesture; /**< Gesture event data */
    SDL_DollarGestureEvent dgesture; /**< Gesture event data */
    SDL_DropEvent drop; /**< Drag and drop event data */
    Uint8 padding[56]; /**< Padding, reserved for future use */
} SDL_Event;
#endif