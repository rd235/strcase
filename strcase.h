/*
 *   Multiway branch (switch) for short strings in C (in one header file)
 *
 *   Copyright (C) 2018  Renzo Davoli <renzo@cs.unibo.it> VirtualSquare team.
 *
 *   This library is free software; you can redistribute it and/or modify it
 *   under the terms of the GNU Lesser General Public License as published by
 *   the Free Software Foundation; either version 2.1 of the License, or (at
 *   your option) any later version.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with this library; if not, write to the Free Software Foundation,
 *   Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef STRCASE_H
#define STRCASE_H
#include <stdint.h>
#include <ctype.h>

#ifndef __cplusplus
/* plain C */
#define __STRCASE_ASCII__ '_'
#define __STRCASE_ASCII_a 'a'
#define __STRCASE_ASCII_b 'b'
#define __STRCASE_ASCII_c 'c'
#define __STRCASE_ASCII_d 'd'
#define __STRCASE_ASCII_e 'e'
#define __STRCASE_ASCII_f 'f'
#define __STRCASE_ASCII_g 'g'
#define __STRCASE_ASCII_h 'h'
#define __STRCASE_ASCII_i 'i'
#define __STRCASE_ASCII_j 'j'
#define __STRCASE_ASCII_k 'k'
#define __STRCASE_ASCII_l 'l'
#define __STRCASE_ASCII_m 'm'
#define __STRCASE_ASCII_n 'n'
#define __STRCASE_ASCII_o 'o'
#define __STRCASE_ASCII_p 'p'
#define __STRCASE_ASCII_q 'q'
#define __STRCASE_ASCII_r 'r'
#define __STRCASE_ASCII_s 's'
#define __STRCASE_ASCII_t 't'
#define __STRCASE_ASCII_u 'u'
#define __STRCASE_ASCII_v 'v'
#define __STRCASE_ASCII_w 'w'
#define __STRCASE_ASCII_x 'x'
#define __STRCASE_ASCII_y 'y'
#define __STRCASE_ASCII_z 'z'
#define __STRCASE_ASCII_A 'A'
#define __STRCASE_ASCII_B 'B'
#define __STRCASE_ASCII_C 'C'
#define __STRCASE_ASCII_D 'D'
#define __STRCASE_ASCII_E 'E'
#define __STRCASE_ASCII_F 'F'
#define __STRCASE_ASCII_G 'G'
#define __STRCASE_ASCII_H 'H'
#define __STRCASE_ASCII_I 'I'
#define __STRCASE_ASCII_J 'J'
#define __STRCASE_ASCII_K 'K'
#define __STRCASE_ASCII_L 'L'
#define __STRCASE_ASCII_M 'M'
#define __STRCASE_ASCII_N 'N'
#define __STRCASE_ASCII_O 'O'
#define __STRCASE_ASCII_P 'P'
#define __STRCASE_ASCII_Q 'Q'
#define __STRCASE_ASCII_R 'R'
#define __STRCASE_ASCII_S 'S'
#define __STRCASE_ASCII_T 'T'
#define __STRCASE_ASCII_U 'U'
#define __STRCASE_ASCII_V 'V'
#define __STRCASE_ASCII_W 'W'
#define __STRCASE_ASCII_X 'X'
#define __STRCASE_ASCII_Y 'Y'
#define __STRCASE_ASCII_Z 'Z'
#define __STRCASE_ASCII_0 '0'
#define __STRCASE_ASCII_1 '1'
#define __STRCASE_ASCII_2 '2'
#define __STRCASE_ASCII_3 '3'
#define __STRCASE_ASCII_4 '4'
#define __STRCASE_ASCII_5 '5'
#define __STRCASE_ASCII_6 '6'
#define __STRCASE_ASCII_7 '7'
#define __STRCASE_ASCII_8 '8'
#define __STRCASE_ASCII_9 '9'
#define __STRCASE_ASCII_bang '!'
#define __STRCASE_ASCII_doublequote '"'
#define __STRCASE_ASCII_hash '#'
#define __STRCASE_ASCII_sharp '#'
#define __STRCASE_ASCII_dollar '$'
#define __STRCASE_ASCII_perc '%'
#define __STRCASE_ASCII_ampersand '&'
#define __STRCASE_ASCII_amp '&'
#define __STRCASE_ASCII_quote '\''
#define __STRCASE_ASCII_lparen '('
#define __STRCASE_ASCII_rparen ')'
#define __STRCASE_ASCII_star '*'
#define __STRCASE_ASCII_plus '+'
#define __STRCASE_ASCII_comma ','
#define __STRCASE_ASCII_minus '-'
#define __STRCASE_ASCII_dot '.'
#define __STRCASE_ASCII_slash '/'
#define __STRCASE_ASCII_colon ':'
#define __STRCASE_ASCII_semicolon ';'
#define __STRCASE_ASCII_less '<'
#define __STRCASE_ASCII_equal '='
#define __STRCASE_ASCII_greater '>'
#define __STRCASE_ASCII_question '?'
#define __STRCASE_ASCII_at '@'
#define __STRCASE_ASCII_lbracket '['
#define __STRCASE_ASCII_backslash '\\'
#define __STRCASE_ASCII_rbracket ']'
#define __STRCASE_ASCII_caret '^'
#define __STRCASE_ASCII_circumflex '^'
#define __STRCASE_ASCII_underline '_'
#define __STRCASE_ASCII_underscore '_'
#define __STRCASE_ASCII_backquote '`'
#define __STRCASE_ASCII_lbrace '{'
#define __STRCASE_ASCII_pipe '|'
#define __STRCASE_ASCII_rbrace '}'
#define __STRCASE_ASCII_tilde '~'
#define __STRCASE_ASCII_space ' '
#define __STRCASE_ASCII_blank ' '

#define __STRCASE_ASCII_ 0
#define __STRCASE_ASCII_END 0
#define __STRCASE_ASCII(X) ((uint64_t) __STRCASE_ASCII_ ## X)

#define __STRCASE(a, b, c, d, e, f, g, h, ...) \
	(__STRCASE_ASCII(a)+(__STRCASE_ASCII(b)<<8)+(__STRCASE_ASCII(c)<<16)+(__STRCASE_ASCII(d)<<24)+ \
	 (__STRCASE_ASCII(e)<<32)+(__STRCASE_ASCII(f)<<40)+(__STRCASE_ASCII(g)<<48)+(__STRCASE_ASCII(h)<<56))
#define STRCASE(...) __STRCASE(__VA_ARGS__ , END, END, END, END, END, END, END, END)
#else
/* C++ */
#define STRCASE(str) \
 (sizeof(str) == 1 ? 0 : (uint64_t)str[0]) + \
 (sizeof(str) <= 2 ? 0 : (uint64_t)str[1] << 8) + \
 (sizeof(str) <= 3 ? 0 : (uint64_t)str[2] << 16) + \
 (sizeof(str) <= 4 ? 0 : (uint64_t)str[3] << 24) + \
 (sizeof(str) <= 5 ? 0 : (uint64_t)str[4] << 32) + \
 (sizeof(str) <= 6 ? 0 : (uint64_t)str[5] << 40) + \
 (sizeof(str) <= 7 ? 0 : (uint64_t)str[6] << 48) + \
 (sizeof(str) <= 8 ? 0 : (uint64_t)str[7] << 56)
#endif

static inline uint64_t strcase(const char *s) {
	int shift;
	uint64_t retval = 0;
	for (shift = 0; *s != 0 && shift < 64; s++, shift += 8)
		retval |= (((uint64_t)*s) << shift);
	return retval;
}

static inline uint64_t strcase_tolower(const char *s) {
	int shift;
	uint64_t retval = 0;
	for (shift = 0; *s != 0 && shift < 64; s++, shift += 8)
		retval |= (((uint64_t) tolower(*s)) << shift);
	return retval;
}

#endif
