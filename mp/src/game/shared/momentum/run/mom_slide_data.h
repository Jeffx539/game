#pragma once

#include "cbase.h"

class CMomPlayerSlideData
{
  public:
    CMomPlayerSlideData();
    ~CMomPlayerSlideData();

    FORCEINLINE void Reset()
    {
        m_bIsEnabled = false;
        m_bStuckToGround = false;
        m_bAllowingJump = false;
        m_bEnableGravity = false;
        m_bFixUpsideSlope = false; 
        // memset(m_bTouchingTrigger, 0, sizeof(m_bTouchingTrigger));
        m_iTouchCounter = 0;
        // m_flGravity = 1.0f;
    }

    FORCEINLINE bool IsEnabled() { return m_bIsEnabled; }

    FORCEINLINE bool IsStuckGround() { return m_bStuckToGround; }

    FORCEINLINE bool IsAllowingJump() { return m_bAllowingJump; }

    FORCEINLINE bool IsGravityEnabled() { return m_bEnableGravity; }

    FORCEINLINE bool IsFixUpsideSlope() { return m_bFixUpsideSlope; }

    FORCEINLINE void SetEnabled() { m_bIsEnabled = true; }

    FORCEINLINE void SetDisabled() { m_bIsEnabled = false; }

    FORCEINLINE void SetStuckToGround(bool bEnable = true) { m_bStuckToGround = bEnable; }

    FORCEINLINE void SetAllowingJump(bool bEnable = true) { m_bAllowingJump = bEnable; }

    FORCEINLINE void SetEnableGravity(bool bEnable = true) { m_bEnableGravity = bEnable; }

    FORCEINLINE void SetFixUpsideSlope(bool bEnable = true) { m_bFixUpsideSlope = bEnable; }

    /*

    FORCEINLINE void SetTouchTrigger(int iIndex, bool bEnable = true) { m_bTouchingTrigger[iIndex] = bEnable; }

    bool IsTouchingOneTrigger()
    {
        bool bReturn = false;

        for (int i = 0; i != MAX_EDICTS + 1; i++)
        {
            if (m_bTouchingTrigger[i])
            {
                bReturn = true;
                break;
            }
        }

        return bReturn;
    }
    */

   
    FORCEINLINE void IncTouchCounter() { m_iTouchCounter++; }

    FORCEINLINE void DecTouchCounter() { m_iTouchCounter--; }

    FORCEINLINE int GetTouchCounter() { return m_iTouchCounter; }
    // FORCEINLINE void SetGravity(float flGravity) { m_flGravity = flGravity; }

    CUtlVector<float> m_flCurrentTriggerMinZ;

  private:
    bool m_bIsEnabled;
    bool m_bStuckToGround;
    bool m_bAllowingJump;
    bool m_bEnableGravity;
    bool m_bFixUpsideSlope;
    uint m_uiTouchCounter;
    // TO BE SURE THAT IT WON'T BUG AGAIN WITH CAPS.
    // bool m_bTouchingTrigger[MAX_EDICTS + 1];
    int m_iTouchCounter;
    // MOM_TODO: Not sure if mapper would like to have a gravity value here, but he could do it with another trigger
    // anyway. float m_flGravity;
};
