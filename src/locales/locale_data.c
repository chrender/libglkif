/*
 * locale_data.c
 *
 * This file is part of fizmo.
 *
 * Copyright (c) 2010-2023 Christoph Ender.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef locale_data_c_INCLUDED
#define locale_data_c_INCLUDED

#include <stdlib.h>

#include <tools/z_ucs.h>
#include <tools/stringmap.h>
#include <tools/i18n.h>

#include "locale_data.h"
#include "libglkif_locales.h"

static stringmap *libglkif_18n_messages = NULL;

static z_ucs locale_data_fr_FR[] = {
  0x0000004e, 0x0000006f, 0x00000074, 0x00000020, 0x00000079, 0x00000065,
  0x00000074, 0x00000020, 0x00000069, 0x0000006d, 0x00000070, 0x0000006c,
  0x00000065, 0x0000006d, 0x00000065, 0x0000006e, 0x00000074, 0x00000065,
  0x00000064, 0x00000020, 0x00000069, 0x0000006e, 0x00000020, 0x0000006c,
  0x00000069, 0x00000062, 0x00000067, 0x0000006c, 0x0000006b, 0x00000069,
  0x00000066, 0x0000002e, 0x00000000
};

static z_ucs *locale_message_ptrs_fr_FR[] = {
  locale_data_fr_FR+   0
};

static locale_messages locale_messages_fr_FR = {
  1,
  locale_message_ptrs_fr_FR
};

static z_ucs locale_data_de_DE[] = {
  0x0000004e, 0x0000006f, 0x00000063, 0x00000068, 0x00000020, 0x0000006e,
  0x00000069, 0x00000063, 0x00000068, 0x00000074, 0x00000020, 0x00000069,
  0x0000006e, 0x00000020, 0x0000006c, 0x00000069, 0x00000062, 0x00000067,
  0x0000006c, 0x0000006b, 0x00000069, 0x00000066, 0x00000020, 0x00000069,
  0x0000006d, 0x00000070, 0x0000006c, 0x00000065, 0x0000006d, 0x00000065,
  0x0000006e, 0x00000074, 0x00000069, 0x00000065, 0x00000072, 0x00000074,
  0x0000002e, 0x00000000
};

static z_ucs *locale_message_ptrs_de_DE[] = {
  locale_data_de_DE+   0
};

static locale_messages locale_messages_de_DE = {
  1,
  locale_message_ptrs_de_DE
};

static z_ucs locale_data_en_GB[] = {
  0x0000004e, 0x0000006f, 0x00000074, 0x00000020, 0x00000079, 0x00000065,
  0x00000074, 0x00000020, 0x00000069, 0x0000006d, 0x00000070, 0x0000006c,
  0x00000065, 0x0000006d, 0x00000065, 0x0000006e, 0x00000074, 0x00000065,
  0x00000064, 0x00000020, 0x00000069, 0x0000006e, 0x00000020, 0x0000006c,
  0x00000069, 0x00000062, 0x00000067, 0x0000006c, 0x0000006b, 0x00000069,
  0x00000066, 0x0000002e, 0x00000000
};

static z_ucs *locale_message_ptrs_en_GB[] = {
  locale_data_en_GB+   0
};

static locale_messages locale_messages_en_GB = {
  1,
  locale_message_ptrs_en_GB
};

locale_module locale_module_libglkif;

static z_ucs locale_code_fr_FR[] = {
  (z_ucs)'f', (z_ucs)'r', (z_ucs)'_', (z_ucs)'F', (z_ucs)'R', (z_ucs)0 };
static z_ucs locale_code_de_DE[] = {
  (z_ucs)'d', (z_ucs)'e', (z_ucs)'_', (z_ucs)'D', (z_ucs)'E', (z_ucs)0 };
static z_ucs locale_code_en_GB[] = {
  (z_ucs)'e', (z_ucs)'n', (z_ucs)'_', (z_ucs)'G', (z_ucs)'B', (z_ucs)0 };


void init_libglkif_locales() {
  locale_module_libglkif.messages_by_localcode = create_stringmap();

  add_stringmap_element(
    locale_module_libglkif.messages_by_localcode,
    locale_code_fr_FR,
    (void*)&locale_messages_fr_FR);
  add_stringmap_element(
    locale_module_libglkif.messages_by_localcode,
    locale_code_de_DE,
    (void*)&locale_messages_de_DE);
  add_stringmap_element(
    locale_module_libglkif.messages_by_localcode,
    locale_code_en_GB,
    (void*)&locale_messages_en_GB);

  locale_module_libglkif.module_name = libglkif_module_name;
}

#endif // locale_data_c_INCLUDED

