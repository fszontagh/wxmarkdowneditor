#ifndef LOGO_64_PNG_H
#define LOGO_64_PNG_H

#include <wx/generic/icon.h>
#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>

inline static const unsigned char logo_64_png[] =
{
	0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00,
	0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x40, 0x08, 0x06, 0x00, 0x00, 0x00, 0xAA,
	0x69, 0x71, 0xDE, 0x00, 0x00, 0x00, 0x06, 0x62, 0x4B, 0x47,
	0x44, 0x00, 0x99, 0x00, 0x99, 0x00, 0x99, 0x5E, 0x44, 0x56,
	0x81, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00,
	0x00, 0x2E, 0x23, 0x00, 0x00, 0x2E, 0x23, 0x01, 0x78, 0xA5,
	0x3F, 0x76, 0x00, 0x00, 0x00, 0x07, 0x74, 0x49, 0x4D, 0x45,
	0x07, 0xE9, 0x02, 0x1B, 0x16, 0x2E, 0x0C, 0x1A, 0x5D, 0xF9,
	0xD1, 0x00, 0x00, 0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x43,
	0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x00, 0x43, 0x72, 0x65,
	0x61, 0x74, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20,
	0x47, 0x49, 0x4D, 0x50, 0x57, 0x81, 0x0E, 0x17, 0x00, 0x00,
	0x02, 0x67, 0x49, 0x44, 0x41, 0x54, 0x78, 0xDA, 0xED, 0x9A,
	0xCD, 0x4B, 0x54, 0x61, 0x14, 0x87, 0x1F, 0xC7, 0x10, 0xAD,
	0x4D, 0x9A, 0x21, 0x4C, 0x93, 0x33, 0xA3, 0x45, 0x62, 0x10,
	0xAE, 0x92, 0x20, 0x21, 0xFF, 0x8D, 0x16, 0x2E, 0x0C, 0xFB,
	0x57, 0xDC, 0x48, 0x8B, 0x76, 0x51, 0x2B, 0xA1, 0x5D, 0xBB,
	0x82, 0x5C, 0xB9, 0xA9, 0xAD, 0x48, 0xD0, 0xC6, 0x34, 0x3F,
	0x46, 0x14, 0x25, 0x2B, 0x3F, 0x48, 0x22, 0xD3, 0x5A, 0x38,
	0x82, 0xBC, 0x9D, 0x73, 0x7D, 0x87, 0xBC, 0x1F, 0xEF, 0xCC,
	0x79, 0x60, 0x16, 0xF7, 0x77, 0xDF, 0xFB, 0xC1, 0xEF, 0x9E,
	0xF3, 0x9E, 0xF3, 0xDE, 0x3B, 0x60, 0x18, 0x86, 0x61, 0x18,
	0x86, 0x61, 0x18, 0x86, 0xD1, 0x80, 0x34, 0x25, 0x78, 0xAD,
	0x5E, 0x60, 0x58, 0xD0, 0x5F, 0x03, 0x9B, 0xA7, 0xB6, 0x73,
	0xC0, 0xA8, 0x30, 0x6E, 0x16, 0x98, 0x39, 0xEF, 0x9B, 0xBA,
	0x90, 0xA0, 0x01, 0xF7, 0x81, 0x31, 0x41, 0x7F, 0xE3, 0x6C,
	0xE7, 0x95, 0x71, 0xE3, 0x71, 0x18, 0x90, 0x4B, 0xD0, 0x80,
	0xB2, 0xA0, 0xED, 0x01, 0x1B, 0x8E, 0x56, 0x54, 0x8E, 0x5F,
	0x88, 0xE3, 0xA6, 0x72, 0x09, 0xA7, 0x80, 0xCB, 0x8A, 0xE7,
	0x38, 0x80, 0x4A, 0xC8, 0x06, 0xE4, 0x80, 0x6E, 0x41, 0x9F,
	0x17, 0x34, 0x29, 0x02, 0xBE, 0x00, 0xBB, 0x21, 0x1B, 0x50,
	0x00, 0x5A, 0x05, 0x7D, 0xD9, 0x33, 0x02, 0x2A, 0x71, 0x3E,
	0x99, 0x24, 0x28, 0x79, 0xE6, 0x75, 0x53, 0x0D, 0x91, 0x12,
	0x94, 0x01, 0x37, 0x14, 0xDD, 0x8D, 0x80, 0x2E, 0xE0, 0x92,
	0x30, 0x6E, 0x35, 0x74, 0x03, 0xA4, 0x0A, 0xB0, 0x0D, 0x6C,
	0xA5, 0x59, 0x01, 0x92, 0x34, 0xA0, 0xC7, 0xB3, 0x02, 0x68,
	0x91, 0xB2, 0x12, 0xB2, 0x01, 0xCD, 0x35, 0xE4, 0xB5, 0x34,
	0xEE, 0x1B, 0xF0, 0x3D, 0xEB, 0xAD, 0xF0, 0x23, 0xA0, 0x5F,
	0xD9, 0xD7, 0x02, 0xDC, 0x55, 0x9E, 0xAA, 0x9B, 0xDB, 0xB7,
	0x81, 0x76, 0x47, 0xFB, 0x51, 0x6D, 0x83, 0x25, 0x9E, 0x00,
	0x6B, 0x59, 0x30, 0x60, 0x02, 0x18, 0x4A, 0x61, 0x2D, 0x33,
	0x02, 0xCC, 0x85, 0xD2, 0x09, 0x66, 0x12, 0x33, 0xA0, 0xD1,
	0x0D, 0x38, 0xAF, 0xE5, 0xF0, 0x5C, 0xC4, 0xB9, 0x06, 0x05,
	0xA3, 0x37, 0x81, 0x45, 0xA1, 0x04, 0x5E, 0x75, 0xB4, 0x9F,
	0x11, 0x13, 0xE0, 0xC9, 0x04, 0x99, 0xE9, 0x17, 0x22, 0x1D,
	0xC0, 0x5B, 0x41, 0x7F, 0x0E, 0xBC, 0x70, 0xB4, 0x67, 0xC0,
	0x80, 0xA3, 0x7D, 0xAC, 0x56, 0x98, 0x60, 0x53, 0x40, 0xEB,
	0xEC, 0x16, 0x3D, 0xC7, 0xCE, 0x87, 0x3E, 0x07, 0xDC, 0xF4,
	0x34, 0xE0, 0x8A, 0x50, 0xFF, 0x63, 0xED, 0x00, 0xD3, 0x8C,
	0x80, 0x5F, 0x42, 0x03, 0xA4, 0x45, 0x4A, 0x5D, 0x46, 0x40,
	0x05, 0x38, 0xF4, 0x8C, 0x94, 0xE0, 0x23, 0x40, 0xEA, 0xED,
	0x97, 0x3C, 0x23, 0x65, 0x87, 0xE3, 0x37, 0x41, 0xB1, 0xF2,
	0xBF, 0x55, 0xA0, 0x1F, 0x78, 0x1C, 0x61, 0xEE, 0xA0, 0xA0,
	0xAF, 0x0B, 0x4F, 0xB6, 0x4F, 0x98, 0x03, 0xF6, 0x81, 0x0F,
	0xCA, 0xB9, 0xDF, 0x03, 0xAF, 0xB2, 0xD0, 0x07, 0x5C, 0x06,
	0xEE, 0xD5, 0x78, 0x4C, 0xBE, 0xFA, 0x3B, 0x8B, 0x8B, 0x11,
	0xE7, 0x5E, 0x0B, 0x25, 0x05, 0xAC, 0x15, 0x36, 0x03, 0xEA,
	0x7C, 0x2D, 0xF0, 0x15, 0x98, 0x56, 0xF6, 0x3D, 0x10, 0x0C,
	0xAE, 0xF0, 0xEF, 0xFB, 0xBD, 0x3B, 0x40, 0xA7, 0xA3, 0x1D,
	0x00, 0xEF, 0x22, 0xAE, 0xFB, 0x29, 0x2B, 0x55, 0x40, 0xA3,
	0x1D, 0x98, 0x12, 0xF4, 0xA7, 0xC0, 0x4B, 0x47, 0x9B, 0x04,
	0x6E, 0x39, 0xDA, 0x67, 0xE0, 0x61, 0xC8, 0x29, 0x50, 0x50,
	0xF4, 0x25, 0xE1, 0xFA, 0x45, 0xCF, 0x5E, 0x21, 0x28, 0x03,
	0x7A, 0x14, 0x7D, 0x55, 0x28, 0x89, 0xAD, 0xF5, 0x68, 0xC0,
	0x75, 0x65, 0x0D, 0xE0, 0xD6, 0xEF, 0x72, 0x0D, 0xAB, 0xC5,
	0xA0, 0x0C, 0x28, 0x2B, 0x4F, 0xFF, 0xC8, 0x33, 0x52, 0x82,
	0x8F, 0x80, 0x6E, 0xCF, 0x85, 0x4D, 0x49, 0xD0, 0x0E, 0x88,
	0xF1, 0x53, 0x58, 0x12, 0x06, 0xB4, 0x00, 0xD7, 0x04, 0x7D,
	0x59, 0xD0, 0x7A, 0x95, 0x48, 0xF9, 0x1D, 0xB2, 0x01, 0x05,
	0x8E, 0xBF, 0x06, 0x9D, 0x15, 0x01, 0xDA, 0x7F, 0x06, 0x12,
	0xCB, 0xFF, 0xB8, 0x0C, 0x28, 0x7A, 0xE6, 0x75, 0x1E, 0x68,
	0x4B, 0x33, 0xFF, 0xE3, 0x32, 0x40, 0xCA, 0xEB, 0x3F, 0x42,
	0x5E, 0x97, 0xD2, 0x9E, 0x00, 0x0D, 0xC3, 0x30, 0x0C, 0xC3,
	0x30, 0x0C, 0xC3, 0x68, 0x5C, 0xFE, 0x02, 0x73, 0x87, 0x65,
	0x60, 0xE7, 0x0E, 0x80, 0xED, 0x00, 0x00, 0x00, 0x00, 0x49,
	0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82,
};

inline wxBitmap& logo_64_png_to_wx_bitmap()
{
	static wxMemoryInputStream memIStream( logo_64_png, sizeof( logo_64_png ) );
	static wxImage image( memIStream, wxBITMAP_TYPE_PNG );
	static wxBitmap bmp( image );
	return bmp;
}

inline wxIcon& logo_64_png_to_wx_icon() {
	static wxIcon icon;
	icon.CopyFromBitmap( logo_64_png_to_wx_bitmap() );
	return icon;
}


#endif //LOGO_64_PNG_H
