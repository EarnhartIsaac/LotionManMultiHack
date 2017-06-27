#ifndef _OFFSETS_H
#define _OFFSETS_H

#include <windows.h>

const DWORD m_ArmorValue = 0xB248;
const DWORD m_Collision = 0x318;
const DWORD m_CollisionGroup = 0x470;
const DWORD m_Local = 0x2FAC;
const DWORD m_MoveType = 0x258;
const DWORD m_OriginalOwnerXuidHigh = 0x316C;
const DWORD m_OriginalOwnerXuidLow = 0x3168;
const DWORD m_aimPunchAngle = 0x301C;
const DWORD m_aimPunchAngleVel = 0x3028;
const DWORD m_bGunGameImmunity = 0x38B0;
const DWORD m_bHasDefuser = 0xB258;
const DWORD m_bHasHelmet = 0xB23C;
const DWORD m_bInReload = 0x3245;
const DWORD m_bIsDefusing = 0x38A4;
const DWORD m_bIsScoped = 0x389C;
const DWORD m_bSpotted = 0x939;
const DWORD m_bSpottedByMask = 0x97C;
const DWORD m_dwBoneMatrix = 0x2698;
const DWORD m_fAccuracyPenalty = 0x32C0;
const DWORD m_fFlags = 0x100;
const DWORD m_flFallbackWear = 0x3178;
const DWORD m_flFlashDuration = 0xA308;
const DWORD m_flFlashMaxAlpha = 0xA304;
const DWORD m_flNextPrimaryAttack = 0x31D8;
const DWORD m_hActiveWeapon = 0x2EE8;
const DWORD m_hMyWeapons = 0x2DE8;
const DWORD m_hObserverTarget = 0x3380;
const DWORD m_hOwner = 0x29BC;
const DWORD m_hOwnerEntity = 0x148;
const DWORD m_iAccountID = 0x2FA8;
const DWORD m_iClip1 = 0x3204;
const DWORD m_iCompetitiveRanking = 0x1A44;
const DWORD m_iCompetitiveWins = 0x1B48;
#define m_iCrosshairId  0xB2B4
const DWORD m_iEntityQuality = 0x2F8C;
const DWORD m_iFOVStart = 0x31D8;
#define m_iGlowIndex 0xA320
#define m_iHealth 0xFC
const DWORD m_iItemDefinitionIndex = 0x2F88;
const DWORD m_iItemIDHigh = 0x2FA0;
const DWORD m_iObserverMode = 0x336C;
const DWORD m_iShotsFired = 0xA2C0;
const DWORD m_iState = 0x31F8;
#define m_iTeamNum 0xF0
const DWORD m_lifeState = 0x25B;
const DWORD m_nFallbackPaintKit = 0x3170;
const DWORD m_nFallbackSeed = 0x3174;
const DWORD m_nFallbackStatTrak = 0x317C;
const DWORD m_nForceBone = 0x267C;
const DWORD m_nTickBase = 0x3424;
const DWORD m_rgflCoordinateFrame = 0x440;
const DWORD m_szCustomName = 0x301C;
const DWORD m_szLastPlaceName = 0x35A8;
const DWORD m_vecOrigin = 0x134;
const DWORD m_vecVelocity = 0x110;
const DWORD m_vecViewOffset = 0x104;
const DWORD m_viewPunchAngle = 0x3010;

const DWORD dwClientState = 0x5A3284;
const DWORD dwClientState_GetLocalPlayer = 0x180;
const DWORD dwClientState_Map = 0x28C;
const DWORD dwClientState_MapDirectory = 0x188;
const DWORD dwClientState_MaxPlayer = 0x310;
const DWORD dwClientState_PlayerInfo = 0x5240;
const DWORD dwClientState_State = 0x108;
const DWORD dwClientState_ViewAngles = 0x4D10;
const DWORD dwClientState_IsHLTV = 0x4CC8;
#define dwEntityList 0x4A8A684
const DWORD dwForceAttack = 0x2ECCA08;
const DWORD dwForceAttack2 = 0x2ECCA14;
const DWORD dwForceBackward = 0x2ECCA8C;
const DWORD dwForceForward = 0x2ECCA80;
const DWORD dwForceJump = 0x4F21618;
const DWORD dwForceLeft = 0x2ECCA68;
const DWORD dwForceRight = 0x2ECCA74;
const DWORD dwGameDir = 0x641A58;
const DWORD dwGameRulesProxy = 0x4F8BF3C;
const DWORD dwGetAllClasses = 0x4F8C010;
const DWORD dwGlobalVars = 0x5A2F88;
#define dwGlowObjectManager 0x4FA7690
const DWORD dwInput = 0x4ED52A8;
const DWORD dwInterfaceLinkList = 0x6E9264;
#define dwLocalPlayer 0xAADFFC
const DWORD dwMouseEnable = 0xAB3860;
const DWORD dwMouseEnablePtr = 0xAB3830;
const DWORD dwPlayerResource = 0x2ECAD8C;
const DWORD dwRadarBase = 0x4EBF37C;
const DWORD dwSensitivity = 0xAB36FC;
const DWORD dwSensitivityPtr = 0xAB36D0;
const DWORD dwViewMatrix = 0x4A7C0E4;
const DWORD dwWeaponTable = 0x4ED1840;
const DWORD dwWeaponTableIndex = 0x3270;
const DWORD dwYawPtr = 0xAB34C0;
const DWORD dwZoomSensitivityRatioPtr = 0xAB8528;
const DWORD dwbSendPackets = 0xCD53A;
const DWORD dwppDirect3DDevice9 = 0x9CF40;
const DWORD dwSetClanTag = 0x87310;
const DWORD m_pStudioHdr = 0x293C;

#endif
