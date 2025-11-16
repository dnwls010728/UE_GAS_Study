#include "GameplayTags/GSTags.h"

namespace GSTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(None, "GSTags.None", "None 태그")
	
	namespace SetByCaller
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Projectile, "GSTags.SetByCaller.Projectile", "발사체에 대한 발신자 크기별 태그")
	}
	
	namespace GSAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "GSTags.GSAbilities.ActivateOnGiven", "한 번 주어지면 즉시 활성화되어야 하는 능력 태그")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "GSTags.GSAbilities.Primary", "기본 능력 태그")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "GSTags.GSAbilities.Secondary", "2차 능력 태그")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "GSTags.GSAbilities.Tertiary", "3차 능력 태그")
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attack, "GSTags.GSAbilities.Enemy.Attack", "적의 공격 태그")
		}
	}

	namespace Events
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "GSTags.Events.KillScored", "킬 점수 이벤트 태그")
		
		namespace Player
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GSTags.Events.Player.HitReact", "플레이어의 적중 반응 이벤트 태그")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Death, "GSTags.Events.Player.Death", "플레이어의 사망 이벤트 태그")
		}
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GSTags.Events.Enemy.HitReact", "적의 적중 반응 이벤트 태그")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(EndAttack, "GSTags.Events.Enemy.EndAttack", "적의 공격 종료 이벤트 태그")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeTraceHit, "GSTags.Events.Enemy.MeleeTraceHit", "적의 근접 추적 피격 태그")
		}
	}
}