// images.h
// contains image buffers for simple space invaders
// Jonathan Valvano, March 5, 2018
// Capture image dimensions from BMP files

#ifndef __images_h
#define __images_h
#include <stdint.h>


// *************************** Images ***************************
//Player's ship
//18x18
const unsigned short usership[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x52AA, 0x6B4D, 0x738E, 0x0000, 0x0000, 0x6B6D, 0x6B4D, 0x5ACB, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA514, 0xAD75, 0xA514, 0xB596, 0x632C, 0x632C, 0xB5B6, 0xA514, 0xAD75, 0xA534,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA514, 0xCE59, 0x9CD3, 0xD69A, 0x8C71, 0x8C71, 0xD69A, 0x94B2,
 0xCE59, 0xA514, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x9492, 0xAD55, 0xA514, 0xD6BA, 0xB596, 0xB596,
 0xD6BA, 0xA514, 0xAD55, 0x9492, 0xC638, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAD75, 0xB596, 0xB5B6, 0xDEDB, 0xB5B6,
 0x9CD3, 0x9CD3, 0xB5B6, 0xDEDB, 0xB5B6, 0xB596, 0xAD75, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xCE79, 0xCE79, 0xDEDB, 0xCE79,
 0xA514, 0xDEFB, 0xD6BA, 0xD6BA, 0xDEFB, 0xA514, 0xCE79, 0xDEDB, 0xCE79, 0xCE79, 0x0000, 0x0000, 0x0000, 0xB596, 0x94B2, 0xAD75,
 0xAD75, 0xB5B6, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB596, 0xB5B6, 0xAD75, 0xAD75, 0x94B2, 0xB596, 0x0000, 0x0000, 0x8C71,
 0xBDF7, 0x8C51, 0xAD55, 0x9CD3, 0xA534, 0xA514, 0x7B8D, 0x7B8D, 0x9CF4, 0xA534, 0x9CD3, 0xAD55, 0x8C51, 0xBDF7, 0x8C71, 0x0000,
 0x0000, 0x630C, 0xA514, 0x9CD3, 0x9CF3, 0x9CF3, 0x9492, 0xAD55, 0x8C30, 0x8C30, 0xAD55, 0x9492, 0x9CF3, 0x9CF3, 0x9CD3, 0xA514,
 0x630C, 0x0000, 0x0000, 0x0000, 0xAD55, 0xC618, 0xC638, 0xCE79, 0xD6BA, 0xC638, 0xC618, 0xC618, 0xC638, 0xD6BA, 0xCE79, 0xC638,
 0xC618, 0xAD55, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBDF7, 0xD69A, 0xDEDB, 0xE71C, 0xF7BE, 0x630C, 0x632C, 0xF7BE, 0xE71C,
 0xDEDB, 0xD69A, 0xBDF7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB596, 0xCE79, 0xD6BA, 0xDEDB, 0xCE59, 0x5AEB, 0x5AEB,
 0xCE59, 0xDEDB, 0xD6BA, 0xCE79, 0xB596, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8C71, 0xAD55, 0xB5B6, 0xA534,
 0x8430, 0x8430, 0xAD55, 0xB5B6, 0xAD55, 0x8C71, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF,
 0xC618, 0x738E, 0x94B2, 0x94B2, 0x738E, 0xC638, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xBDF7, 0x7BEF, 0xDEFC, 0x940F, 0x940F, 0xDEFB, 0x7BEF, 0xBDF7, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0xEF9E, 0x93CD, 0x93CD, 0xEF9E, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6B4D, 0xEF5D, 0x83EF, 0x83EF, 0xEF5D, 0x6B4D, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA534, 0x0000, 0x0000, 0x0000, 0x0000, 0xA534, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000,

};

//userlaser
//11x11
const unsigned short userlaser[] = {
 0x0000, 0x0000, 0x0000, 0x3841, 0xECAD, 0xECAD, 0x3841, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x40A2, 0xF4AE, 0xFFFC, 0xFFFC,
 0xF4AE, 0x40A2, 0x0000, 0x0000, 0x0000, 0x1000, 0xF3AB, 0xF7F9, 0xFFFF, 0xFFFF, 0xF7F9, 0xF3AB, 0x1000, 0x0000, 0x0000, 0x1000,
 0xE36A, 0xF798, 0xFFFF, 0xFFFF, 0xF798, 0xE36A, 0x1000, 0x0000, 0x0000, 0x1000, 0xE36A, 0xF798, 0xFFFF, 0xFFFF, 0xF798, 0xE36A,
 0x1000, 0x0000, 0x0000, 0x1000, 0xE36A, 0xF798, 0xFFFF, 0xFFFF, 0xF798, 0xE36A, 0x1000, 0x0000, 0x0000, 0x1000, 0xE36A, 0xF798,
 0xFFFF, 0xFFFF, 0xF798, 0xE36A, 0x1000, 0x0000, 0x0000, 0x1000, 0xF3AB, 0xF7F9, 0xFFFF, 0xFFFF, 0xF7F9, 0xF3AB, 0x1000, 0x0000,
 0x0000, 0x0000, 0x40A2, 0xF4AE, 0xFFFC, 0xFFFC, 0xF4AE, 0x40A2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3841, 0xECAD, 0xECAD,
 0x3841, 0x0000, 0x0000, 0x0000,

};

//enemylaser
//11x11
const unsigned short enemylaser[] = {
 0x0000, 0x0000, 0x0000, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E5F, 0x079F, 0xFFFF,
 0xFFFF, 0xFFFF, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0E5F, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x0E5F,
 0x0000, 0x0000, 0x0E5F, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0E5F, 0x079F, 0xFFFF,
 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0E5F, 0x079F, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x079F,
 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0E5F, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E5F,
 0x079F, 0x079F, 0xFFFF, 0x079F, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E5F, 0x079F, 0xFFFF, 0x079F, 0x0E5F,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E5F, 0x079F, 0x079F, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0E5F, 0x079F, 0x0E5F, 0x0000, 0x0000, 0x0000, 0x0000,

};
//when enemy ship is dead, cover with a black box: apropriate height and width will be adjusted when printing program
const unsigned short Black[160] = {0};

// enemy ship that starts at the top of the screen (arms/mouth closed)
// width=16 x height=10
const unsigned short SmallEnemy10pointA[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
//18x8 (wxh)
const unsigned short ns[] = {
 0xE7FF, 0x0000, 0xBF7F, 0xA71F, 0x8E9F, 0x6D9D, 0x4C9C, 0x54DF, 0x337D, 0x231D, 0x22FD, 0x2B5C, 0x3BFE, 0x653F, 0x4439, 0x8E7F,
 0x9EDF, 0xB75F, 0xF7FF, 0xDFDF, 0xC79F, 0xAF3F, 0x9EDF, 0x865F, 0x75FF, 0x6D7F, 0x443D, 0x2B7B, 0x339C, 0x33BB, 0x54DE, 0x6D9F,
 0x863F, 0x8E9F, 0xA6FF, 0xBF7F, 0xF7FF, 0x0000, 0xCFBF, 0xAF3F, 0xAF3F, 0x969F, 0x8E5F, 0x7E1F, 0x653E, 0x2B98, 0x3C3A, 0x33F9,
 0x7DFF, 0x7E3F, 0x96BF, 0x9EFF, 0xAF3F, 0xBF7F, 0xFFFF, 0xF7FF, 0xD7DF, 0xCFBF, 0xBF7F, 0x9EFF, 0x9EDF, 0x969F, 0x7E1F, 0x4C99,
 0x4CBA, 0x54FB, 0x969F, 0x96BF, 0xA6FF, 0xAF3F, 0xBF7F, 0xCFBF, 0x0000, 0xF7FF, 0xEFFF, 0xD7DF, 0xC79F, 0xB75F, 0xAF3F, 0x9EDF,
 0xA71F, 0x5D19, 0x5CF8, 0x75DC, 0xA71F, 0xA71F, 0xB75F, 0xBF7F, 0xD7DF, 0xE7DF, 0x0000, 0xFFFF, 0xF7FF, 0xE7FF, 0xD7DF, 0xC79F,
 0xBF7F, 0xB75F, 0xB77F, 0x8E3B, 0x64F6, 0xAF3F, 0xBF7F, 0xBF7F, 0xC79F, 0xCFBF, 0x0000, 0xEFFF, 0x0000, 0x0000, 0x0000, 0xF7FF,
 0xEFFF, 0xDFDF, 0xCFBF, 0xC79F, 0xC79F, 0xBF7F, 0x9E5B, 0xC7BF, 0xC79F, 0xCFBF, 0xDFDF, 0xE7DF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xEFFF, 0xE7FF, 0xDFDF, 0xDFFF, 0xDFFF, 0xD7BF, 0xDFDF, 0xE7FF, 0x0000, 0xFFFF, 0x0000, 0xFFFF
};


//18x8
const unsigned short sp[] = {
 0x0000, 0x0000, 0xBF7F, 0xA71F, 0x8E9F, 0x6D9D, 0x4C9C, 0x54DF, 0x337D, 0x231D, 0x22FD, 0x2B5C, 0x3BFE, 0x653F, 0x4439, 0x8E7F,
 0x9EDF, 0xB75F, 0xF7FF, 0x0000, 0xC79F, 0xAF3F, 0x9EDF, 0x865F, 0x75FF, 0x6D7F, 0x443D, 0x2B7B, 0x339C, 0x33BB, 0x54DE, 0x6D9F,
 0x863F, 0x8E9F, 0xA6FF, 0xBF7F, 0xF7FF, 0xE7DF, 0xCFBF, 0xAF3F, 0xAF3F, 0x969F, 0x8E5F, 0x7E1F, 0x653E, 0x2B98, 0x3C3A, 0x33F9,
 0x7DFF, 0x7E3F, 0x96BF, 0x9EFF, 0xAF3F, 0xBF7F, 0x0000, 0xF7FF, 0xD7DF, 0xCFBF, 0xBF7F, 0x9EFF, 0x9EDF, 0x969F, 0x7E1F, 0x4C99,
 0x4CBA, 0x54FB, 0x969F, 0x96BF, 0xA6FF, 0xAF3F, 0xBF7F, 0x0000, 0x0000, 0xF7FF, 0xEFFF, 0xD7DF, 0xC79F, 0xB75F, 0xAF3F, 0x9EDF,
 0xA71F, 0x5D19, 0x5CF8, 0x75DC, 0xA71F, 0xA71F, 0xB75F, 0xBF7F, 0xD7DF, 0xE7DF, 0x0000, 0xFFFF, 0xF7FF, 0xE7FF, 0xD7DF, 0xC79F,
 0xBF7F, 0xB75F, 0xB77F, 0x8E3B, 0x64F6, 0xAF3F, 0xBF7F, 0xBF7F, 0xC79F, 0xCFBF, 0xDFDF, 0x0000, 0x0000, 0x0000, 0x0000, 0xF7FF,
 0xEFFF, 0xDFDF, 0xCFBF, 0xC79F, 0xC79F, 0xBF7F, 0x9E5B, 0xC7BF, 0xC79F, 0xCFBF, 0xDFDF, 0xE7DF, 0xF7FF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xEFFF, 0xE7FF, 0xDFDF, 0xDFFF, 0xDFFF, 0xD7BF, 0xDFDF, 0xE7FF, 0xEFFF, 0x0000, 0xFFFF, 0x0000
};


// enemy ship that starts at the top of the screen (arms/mouth open)
// width=16 x height=10
const unsigned short SmallEnemy10pointB[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// enemy ship that starts in the middle of the screen (arms together)
// width=16 x height=10
const unsigned short SmallEnemy20pointA[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// enemy ship that starts in the middle of the screen (arms apart)
// width=16 x height=10
const unsigned short SmallEnemy20pointB[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};



// enemy ship that starts at the bottom of the screen (arms down)
// width=16 x height=10
const unsigned short SmallEnemy30pointA[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// enemy ship that starts at the bottom of the screen (arms up)
// width=16 x height=10
const unsigned short SmallEnemy30pointB[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// image of the player's ship
// includes two blacked out columns on the left and right sides of the image to prevent smearing when moved 2 pixels to the left or right
// width=18 x height=8
const unsigned short PlayerShip0[] = {
 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0,
 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

const unsigned short pship[] = {
 0xE7FF, 0xD7DF, 0xBF7F, 0xA71F, 0x8E9F, 0x6D9D, 0x4C9C, 0x54DF, 0x337D, 0x231D, 0x22FD, 0x2B5C, 0x3BFE, 0x653F, 0x4439, 0x8E7F,
 0x9EDF, 0xB75F, 0x0000, 0xDFDF, 0xC79F, 0xAF3F, 0x9EDF, 0x865F, 0x75FF, 0x6D7F, 0x443D, 0x2B7B, 0x339C, 0x33BB, 0x54DE, 0x6D9F,
 0x863F, 0x8E9F, 0xA6FF, 0xBF7F, 0x0000, 0xE7DF, 0xCFBF, 0xAF3F, 0xAF3F, 0x969F, 0x8E5F, 0x7E1F, 0x653E, 0x2B98, 0x3C3A, 0x33F9,
 0x7DFF, 0x7E3F, 0x96BF, 0x9EFF, 0xAF3F, 0xBF7F, 0xFFFF, 0xF7FF, 0xD7DF, 0xCFBF, 0xBF7F, 0x9EFF, 0x9EDF, 0x969F, 0x7E1F, 0x4C99,
 0x4CBA, 0x54FB, 0x969F, 0x96BF, 0xA6FF, 0xAF3F, 0xBF7F, 0xCFBF, 0x0000, 0xF7FF, 0xEFFF, 0xD7DF, 0xC79F, 0xB75F, 0xAF3F, 0x9EDF,
 0xA71F, 0x5D19, 0x5CF8, 0x75DC, 0xA71F, 0xA71F, 0xB75F, 0xBF7F, 0xD7DF, 0xE7DF, 0x0000, 0xFFFF, 0xF7FF, 0xE7FF, 0xD7DF, 0xC79F,
 0xBF7F, 0xB75F, 0xB77F, 0x8E3B, 0x64F6, 0xAF3F, 0xBF7F, 0xBF7F, 0xC79F, 0xCFBF, 0xDFDF, 0xEFFF, 0x0000, 0x0000, 0x0000, 0xF7FF,
 0xEFFF, 0xDFDF, 0xCFBF, 0xC79F, 0xC79F, 0xBF7F, 0x9E5B, 0xC7BF, 0xC79F, 0xCFBF, 0x0000, 0xE7DF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xEFFF, 0xE7FF, 0xDFDF, 0xDFFF, 0xDFFF, 0xD7BF, 0xDFDF, 0xE7FF, 0xEFFF, 0xFFFF, 0x0000, 0x0000
};

// small shield floating in space to cover the player's ship from enemy fire (undamaged)
// width=18 x height=5
const unsigned short Bunker0[] = {
 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000, 0x0000, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000,

};

#endif /* __images_h */