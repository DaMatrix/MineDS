#include "game/game_main.h"
#include "API/font.h"

void setFont(font* f)
{
	currentFont=f;
}

void loadFont(font* f, u8 charsize)
{
	int i, j;
	int param;
	uint8 texX, texy;
	u8 buffer[512*64/4];
	sImage pcx; 
	u8 *buffer2;
	u16 palette[4];
	
	buffer2=DS_OpenFile("HUD.pcx", "font", true, true);

	loadPCX((u8*)buffer2, &pcx);
	
	palette[0]=RGB15(31,0,31);
	palette[1]=RGB15(31,31,31);
	palette[2]=RGB15(0,0,0);
	palette[3]=RGB15(0,0,0);
	
	for(j=0;j<64;j++)
	{
		for(i=0;i<512/4;i++)
		{
			buffer[i+j*512/4]=(pcx.image.data8[i*4+j*512])|((pcx.image.data8[i*4+1+j*512])<<2)|((pcx.image.data8[i*4+2+j*512])<<4)|((pcx.image.data8[i*4+3+j*512])<<6);
		}	
	}
	
	imageDestroy(&pcx);
	free(buffer2);
	
	f->tex.used=true;

	f->tex.width=512;
	f->tex.height=64;	
	f->tex.size=f->tex.width*f->tex.height/4;
		
	Palette_AddToBank(&f->tex, palette, 8*2);
	param = TEXGEN_TEXCOORD | GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | (1<<29);
	
	Texture_GetTexAddress(&f->tex);
	Texture_GetGlWL(f->tex.width, f->tex.height, &texX, &texy);
	
	Texture_SetParameter(&f->tex, texX, texy, f->tex.addr, GL_RGB4, param);

	Texture_AddToBank(&f->tex, buffer, f->tex.bank);
	
	f->charsize=charsize;
	
	setFont(f);
}

void drawChar(char c, u16 color, int32 x, int32 y)
{
	c-=32;
	
	int tx=(c*16)%512;
	int ty=16*(c*16-tx)/512;

	glPushMatrix();

	glColor(color);

	Texture_Bind(&currentFont->tex);
	Palette_Bind4(&currentFont->tex);
	
	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK | POLY_ID(63));
	
	glTranslatef32(x, y, 0);
	
	glScalef32(inttof32(currentFont->charsize),inttof32(currentFont->charsize),inttof32(1));
	
	glBegin(GL_QUADS);
	
		GFX_TEX_COORD = TEXTURE_PACK(inttot16(tx), inttot16(ty));
		GFX_VERTEX10 = t1;
		GFX_TEX_COORD = TEXTURE_PACK(inttot16(tx), inttot16(ty+16));
		GFX_VERTEX10 = t2;
		GFX_TEX_COORD = TEXTURE_PACK(inttot16(tx+16), inttot16(ty+16));
		GFX_VERTEX10 = t3;
		GFX_TEX_COORD = TEXTURE_PACK(inttot16(tx+16), inttot16(ty));
		GFX_VERTEX10 = t4;

	glEnd();
	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK);
	
	glPopMatrix(1);
}

void drawString(char* s, u16 color, int32 size, int32 x, int32 y)
{
	int n=strlen(s);
	int i;
	
	glPushMatrix();
		glTranslatef32(x, y, 0);
		glScalef32(size, size,inttof32(1));
		for(i=0;i<n;i++)
		{
			drawChar(s[i], color, i*inttof32(8), 0);
		}
	glPopMatrix(1);
}
