#include "extdll.h"
#include "util.h"

#include "cbase.h"
#include "pm_shared.h"

#include "characters.h"
#include "player.h"
#include "weapons.h"
int character;

void CCharacter::Spawn(void){
	pev->classname = MAKE_STRING("character");
	pev->health = 100;
	pev->armorvalue = 0;
	pev->takedamage = DAMAGE_AIM;
	pev->solid = SOLID_SLIDEBOX;
	pev->movetype = MOVETYPE_NOCLIP;
	pev->max_health = pev->health;
	pev->flags &= FL_PROXY;	// keep proxy flag sey by engine
	pev->flags |= FL_CLIENT;
	pev->effects = 0;
	pev->deadflag = DEAD_NO;
	pev->dmg_take = 0;
	pev->dmg_save = 0;
	pev->friction = 0;
	pev->gravity = 0;
	m_bitsDamageType = 0;


	switch (character)
	{
	case gordon:
		SET_MODEL(ENT(pev), "models/player.mdl");
		break;
	case scientist:
		SET_MODEL(ENT(pev), "models/scientist.mdl");
		baseSequence = 74;
		pev->sequence = baseSequence;
		break;
	default:
		break;
	}
	ResetSequenceInfo();
	pev->frame = 0;

	UTIL_SetOrigin(pev, pev->origin);
	SetThink(&CCharacter::characterThink);
	pev->nextthink = gpGlobals->time + 0.1;
}


void CCharacter::setPosition(CBasePlayer *m_pPlayer){
	pev->angles = m_pPlayer->pev->angles;
	pev->velocity = (m_pPlayer->pev->origin - pev->origin) * 100;			//Hack - removes jitter you get form setting the origin directly
}

void CCharacter::characterThink(void){
	StudioFrameAdvance();
	ALERT(at_console, "NOT DONE");
	if (m_fSequenceFinished){
		ALERT(at_console, "DONE\n");
		pev->sequence = baseSequence;
		ResetSequenceInfo();
		pev->frame = 0;
	}

	pev->nextthink = gpGlobals->time + 0.1;
}
