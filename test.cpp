// #include <Windows.h>
// #include <SDL.h>

// int main(int argc, char* argv[]) {
//     // Load the SDL2.dll library
//     HINSTANCE hInstance = LoadLibraryA("SDL2.dll");
//     if (hInstance == NULL) {
//         MessageBoxA(NULL, "Failed to load SDL2.dll", "Error", MB_OK | MB_ICONERROR);
//         return 1;
//     }

//     // Get the addresses of the SDL functions
//     typedef int(*SDL_Init_t)(Uint32 flags);
//     typedef SDL_Window* (*SDL_CreateWindow_t)(const char* title, int x, int y, int w, int h, Uint32 flags);
//     typedef SDL_Renderer* (*SDL_CreateRenderer_t)(SDL_Window* window, int index, Uint32 flags);
//     typedef void(*SDL_SetRenderDrawColor_t)(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
//     typedef void(*SDL_RenderClear_t)(SDL_Renderer* renderer);
//     typedef void(*SDL_RenderPresent_t)(SDL_Renderer* renderer);
//     typedef int(*SDL_PollEvent_t)(SDL_Event* event);

//     SDL_Init_t SDL_Init = (SDL_Init_t)GetProcAddress(hInstance, "SDL_Init");
//     SDL_CreateWindow_t SDL_CreateWindow = (SDL_CreateWindow_t)GetProcAddress(hInstance, "SDL_CreateWindow");
//     SDL_CreateRenderer_t SDL_CreateRenderer = (SDL_CreateRenderer_t)GetProcAddress(hInstance, "SDL_CreateRenderer");
//     SDL_SetRenderDrawColor_t SDL_SetRenderDrawColor = (SDL_SetRenderDrawColor_t)GetProcAddress(hInstance, "SDL_SetRenderDrawColor");
//     SDL_RenderClear_t SDL_RenderClear = (SDL_RenderClear_t)GetProcAddress(hInstance, "SDL_RenderClear");
//     SDL_RenderPresent_t SDL_RenderPresent = (SDL_RenderPresent_t)GetProcAddress(hInstance, "SDL_RenderPresent");
//     SDL_PollEvent_t SDL_PollEvent = (SDL_PollEvent_t)GetProcAddress(hInstance, "SDL_PollEvent");

//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         MessageBoxA(NULL, "Failed to initialize SDL", "Error", MB_OK | MB_ICONERROR);
//         return 1;
//     }

//     // Create a window and renderer
//     SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//     // Set the renderer draw color to red
//     SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

//     // Render a rectangle to the screen
//     SDL_Rect rect = { 100, 100, 100, 100 };
//     SDL_RenderFillRect(renderer, &rect);

//     // Update the screen
//     SDL_RenderPresent(renderer);

//     // Main loop
//     SDL_Event event;
//     while (1) {
//         // Poll for events
//         if (SDL_PollEvent(&event)) {
//             // If the user clicked the mouse
//             if (event.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX = event.button.x;
//                 int mouseY = event.button.y;
//                 MessageBoxA(NULL, ("Mouse clicked at " + std::to_string(mouseX) + ", " + std::to_string(mouseY)).c_str(), "Mouse Click", MB_OK | MB_ICONINFORMATION);
//             }
//             // If the user quit the application
//             else if (event.type == SDL_QUIT) {
//                 break;
//             }
//         }
//     }

