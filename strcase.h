/*
 *   Multiway branch (switch) for short strings in C (in one header file)
 *
 *   Copyright (C) 2018  Renzo Davoli <renzo@cs.unibo.it> VirtualSquare team.
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef STRCASE_H
#define STRCASE_H
#include <stdint.h>

#define _ASCII__ 0x5f
#define _ASCII_a 0x61
#define _ASCII_b 0x62
#define _ASCII_c 0x63
#define _ASCII_d 0x64
#define _ASCII_e 0x65
#define _ASCII_f 0x66
#define _ASCII_g 0x67
#define _ASCII_h 0x68
#define _ASCII_i 0x69
#define _ASCII_j 0x6a
#define _ASCII_k 0x6b
#define _ASCII_l 0x6c
#define _ASCII_m 0x6d
#define _ASCII_n 0x6e
#define _ASCII_o 0x6f
#define _ASCII_p 0x70
#define _ASCII_q 0x71
#define _ASCII_r 0x72
#define _ASCII_s 0x73
#define _ASCII_t 0x74
#define _ASCII_u 0x75
#define _ASCII_v 0x76
#define _ASCII_w 0x77
#define _ASCII_x 0x78
#define _ASCII_y 0x79
#define _ASCII_z 0x7a
#define _ASCII_A 0x41
#define _ASCII_B 0x42
#define _ASCII_C 0x43
#define _ASCII_D 0x44
#define _ASCII_E 0x45
#define _ASCII_F 0x46
#define _ASCII_G 0x47
#define _ASCII_H 0x48
#define _ASCII_I 0x49
#define _ASCII_J 0x4a
#define _ASCII_K 0x4b
#define _ASCII_L 0x4c
#define _ASCII_M 0x4d
#define _ASCII_N 0x4e
#define _ASCII_O 0x4f
#define _ASCII_P 0x50
#define _ASCII_Q 0x51
#define _ASCII_R 0x52
#define _ASCII_S 0x53
#define _ASCII_T 0x54
#define _ASCII_U 0x55
#define _ASCII_V 0x56
#define _ASCII_W 0x57
#define _ASCII_X 0x58
#define _ASCII_Y 0x59
#define _ASCII_Z 0x5a
#define _ASCII_0 0x30
#define _ASCII_1 0x31
#define _ASCII_2 0x32
#define _ASCII_3 0x33
#define _ASCII_4 0x34
#define _ASCII_5 0x35
#define _ASCII_6 0x36
#define _ASCII_7 0x37
#define _ASCII_8 0x38
#define _ASCII_9 0x39
#define _ASCII_bang 0x21
#define _ASCII_doublequote 0x22
#define _ASCII_hash 0x23
#define _ASCII_sharp 0x23
#define _ASCII_dollar 0x24
#define _ASCII_perc 0x25
#define _ASCII_ampersand 0x26
#define _ASCII_amp 0x26
#define _ASCII_quote 0x27
#define _ASCII_lparen 0x28
#define _ASCII_rparen 0x29
#define _ASCII_star 0x2a
#define _ASCII_plus 0x2b
#define _ASCII_comma 0x2c
#define _ASCII_minus 0x2d
#define _ASCII_dot 0x2e
#define _ASCII_slash 0x2f
#define _ASCII_colon 0x3a
#define _ASCII_semicolon 0x3b
#define _ASCII_less 0x3c
#define _ASCII_equal 0x3d
#define _ASCII_greater 0x3e
#define _ASCII_question 0x3f
#define _ASCII_at 0x40
#define _ASCII_lbracket 0x5b
#define _ASCII_backslash 0x5c
#define _ASCII_rbracket 0x5d
#define _ASCII_caret 0x5e
#define _ASCII_circumflex 0x5e
#define _ASCII_underline 0x5f
#define _ASCII_underscore 0x5f
#define _ASCII_backquote 0x60
#define _ASCII_lbrace 0x7b
#define _ASCII_pipe 0x7c
#define _ASCII_rbrace 0x7d
#define _ASCII_tilde 0x7e

#define _ASCII_END 0x0
#define _ASCII(X) ((uint64_t) _ASCII_ ## X)

#define _STRCASE(a, b, c, d, e, f, g, h, ...) \
  (_ASCII(a)+(_ASCII(b)<<8)+(_ASCII(c)<<16)+(_ASCII(d)<<24)+ \
   (_ASCII(e)<<32)+(_ASCII(f)<<40)+(_ASCII(g)<<48)+(_ASCII(h)<<56))
#define STRCASE(...) _STRCASE(__VA_ARGS__ , END, END, END, END, END, END, END, END)

static inline uint64_t strcase(const char *s) {
	int shift;
	uint64_t retval = 0;
	for (shift = 0; *s != 0 && shift < 64; s++, shift += 8)
		retval |= (((uint64_t)*s) << shift);
	return retval;
}

#endif
