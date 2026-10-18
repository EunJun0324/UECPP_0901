#include "Widgets/C_EnemyWidget.h"
#include "Components/ProgressBar.h"

void UC_EnemyWidget::UpdateHealth(float maxHp, float Hp)
{
	ProgressBar_Health->SetPercent(Hp / maxHp);
}
