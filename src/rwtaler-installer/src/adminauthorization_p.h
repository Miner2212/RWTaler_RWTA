#ifndef QTRWTAUPDATER_ADMINAUTHORIZATION_P_H
#define QTRWTAUPDATER_ADMINAUTHORIZATION_P_H

#include "rwtalerupdater/adminauthoriser.h"

namespace QtRWTalerUpdater
{

class AdminAuthorization : public AdminAuthoriser
{
public:
	bool hasAdminRights() override;
	bool executeAsAdmin(const QString &program, const QStringList &arguments) override;
};

}

#endif // QTRWTAUPDATER_ADMINAUTHORIZATION_P_H
