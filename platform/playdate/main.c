#include "stdio.h"

#include "playdate.h"

// package main
// 
// import "base:runtime"
// 
// import pd "../../libs/odin-playdate"
// 
// import "platform/core"
// import "../game"
// 
// ctx : runtime.Context
// 
// font_path :: "/System/Fonts/Asheville-Sans-14-Bold.pft";
// 
// @(export)
// eventHandler :: proc "c" (api: ^pd.Api, event: pd.System_Event, arg: u32) -> i32 {
//     #partial switch event {
//         case .Init: {
//             ctx = pd.playdate_context_create(api)
//             context = ctx
// 
//             err : cstring
//             core.default_font = api.graphics.load_font(font_path, &err)
// 
//             assert(core.default_font != nil, "couldn't load font")
// 
//             api.system.set_update_callback(update, api)
//             game.init()
//         }
//         case .Terminate: {
//             context = ctx
//             game.deinit()
//             pd.playdate_context_destroy(&ctx)
//         }
//     }
// 
//     return 0
// }
// 
// update :: proc "c" (user_data: rawptr) -> pd.Update_Result{
//     context = ctx
//     context.user_ptr = user_data
// 
//     api := cast(^pd.Api)user_data
// 
//     dt := api.system.get_elapsed_time()
//     api.system.reset_elapsed_time()
//     game.update(dt)
// 
//     return .Update_Display
// }
// 