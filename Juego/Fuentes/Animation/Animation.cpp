#include "Animation.h"
#include "AdmTexturas.h"
#include <iostream>

using namespace std;


void Animation::Update()
{
    m_spriteFrame = (SDL_GetTicks()/m_AnimSpeed)% m_FrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
    AdmTexturas::getInstancia()->drawFrame(m_TextureID, x, y, spriteWidth,  spriteHeight, m_spriteRow, m_spriteFrame, m_Flip);
}

void Animation::SetProps(string textureID, int spriteRow, int frameCount, int animSpeed, SDL_RendererFlip flip)
{
    m_TextureID = textureID;
    m_spriteRow = spriteRow;
    m_FrameCount = frameCount;
    m_AnimSpeed = animSpeed;
    m_Flip = flip;
}
