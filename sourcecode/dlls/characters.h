#include "player.h"
class CCharacter : public CBaseMonster
{
public:
	virtual void Spawn(void);

	void setPosition(CBasePlayer *m_pPlayer);
	
};