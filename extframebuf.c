/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#define MICROPY_PY_FRAMEBUF (1)

#include "py/dynruntime.h"

#if !defined(__linux__)
void *memset(void *s, int c, size_t n) {
    return mp_fun_table.memset_(s, c, n);
}
#endif

mp_obj_type_t mp_type_framebuf;

#include "modframebuf.c"

mp_map_elem_t framebuf_locals_dict_table[10];
STATIC MP_DEFINE_CONST_DICT(framebuf_locals_dict, framebuf_locals_dict_table);

mp_obj_t mpy_init(mp_obj_fun_bc_t *self, size_t n_args, size_t n_kw, mp_obj_t *args) {
    MP_DYNRUNTIME_INIT_ENTRY

    mp_type_framebuf.base.type = (void*)&mp_type_type;
    mp_type_framebuf.name = MP_QSTR_FrameBuffer;
    mp_type_framebuf.make_new = framebuf_make_new;
    mp_type_framebuf.buffer_p.get_buffer = framebuf_get_buffer;
    framebuf_locals_dict_table[0] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_fill), MP_OBJ_FROM_PTR(&framebuf_fill_obj) };
    framebuf_locals_dict_table[1] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_fill_rect), MP_OBJ_FROM_PTR(&framebuf_fill_rect_obj) };
    framebuf_locals_dict_table[2] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_pixel), MP_OBJ_FROM_PTR(&framebuf_pixel_obj) };
    framebuf_locals_dict_table[3] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_hline), MP_OBJ_FROM_PTR(&framebuf_hline_obj) };
    framebuf_locals_dict_table[4] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_vline), MP_OBJ_FROM_PTR(&framebuf_vline_obj) };
    framebuf_locals_dict_table[5] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_rect), MP_OBJ_FROM_PTR(&framebuf_rect_obj) };
    framebuf_locals_dict_table[6] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_line), MP_OBJ_FROM_PTR(&framebuf_line_obj) };
    framebuf_locals_dict_table[7] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_blit), MP_OBJ_FROM_PTR(&framebuf_blit_obj) };
    framebuf_locals_dict_table[8] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_scroll), MP_OBJ_FROM_PTR(&framebuf_scroll_obj) };
    framebuf_locals_dict_table[9] = (mp_map_elem_t){ MP_OBJ_NEW_QSTR(MP_QSTR_text), MP_OBJ_FROM_PTR(&framebuf_text_obj) };
    mp_type_framebuf.locals_dict = (void*)&framebuf_locals_dict;

    mp_store_global(MP_QSTR_FrameBuffer, MP_OBJ_FROM_PTR(&mp_type_framebuf));
    mp_store_global(MP_QSTR_FrameBuffer1, MP_OBJ_FROM_PTR(&legacy_framebuffer1_obj));
    mp_store_global(MP_QSTR_MVLSB, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_MVLSB));
    mp_store_global(MP_QSTR_MONO_VLSB, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_MVLSB));
    mp_store_global(MP_QSTR_RGB565, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_RGB565));
    mp_store_global(MP_QSTR_GS2_HMSB, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_GS2_HMSB));
    mp_store_global(MP_QSTR_GS4_HMSB, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_GS4_HMSB));
    mp_store_global(MP_QSTR_GS8, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_GS8));
    mp_store_global(MP_QSTR_MONO_HLSB, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_MHLSB));
    mp_store_global(MP_QSTR_MONO_HMSB, MP_OBJ_NEW_SMALL_INT(FRAMEBUF_MHMSB));

    MP_DYNRUNTIME_INIT_EXIT
}
