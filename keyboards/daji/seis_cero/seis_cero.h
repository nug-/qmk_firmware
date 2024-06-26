/* Copyright 2023 Otus Engineering
 * 
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 2 of the License, or 
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */ 

#pragma once

#include "quantum.h"

#define ___ KC_NO

/* Default layout with full backspace
 */
#define LAYOUT_default( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,      \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, \
  K40,      K42, K43,                K47,                K4B,      K4D, K4E  \
) \
{ \
  {K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, ___}, \
  {K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, ___}, \
  {K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, ___, K2D, ___}, \
  {K30, ___, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, ___, K3D, K3E}, \
  {K40, ___, K42, K43, ___, ___, ___, K47, ___, ___, ___, K4B, ___, K4D, K4E}  \
}

/* Default layout with split backspace
 */
#define LAYOUT_all( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, \
  K40,      K42, K43,                K47,                K4B,      K4D, K4E  \
) \
{ \
  {K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E}, \
  {K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, ___}, \
  {K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, ___, K2D, ___}, \
  {K30, ___, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, ___, K3D, K3E}, \
  {K40, ___, K42, K43, ___, ___, ___, K47, ___, ___, ___, K4B, ___, K4D, K4E}  \
}
