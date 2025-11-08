#include "GameplayTags/GSTags.h"

namespace GSTags
{
	namespace GSAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "GSTags.GSAbilities.ActivateOnGiven", "한 번 주어지면 즉시 활성화되어야 하는 능력 태그")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "GSTags.GSAbilities.Primary", "기본 능력 태그")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "GSTags.GSAbilities.Secondary", "2차 능력 태그")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "GSTags.GSAbilities.Tertiary", "3차 능력 태그")
	}

	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GSTags.Events.Enemy.HitReact", "적의 적중 반응 이벤트 태그")
		}
	}
}