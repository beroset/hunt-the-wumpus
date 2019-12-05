/* hunt the wumpus, gui implementation using C++ and QT
 * Copyright (C) 2019  Sandro Wißmann
 *
 * hunt the wumpus is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * hunt the wumpus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hunt the wumpus. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: https://github.com/sandro4912/hunt-the-wumpus
 */

#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"

GameOverDialog::GameOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

void GameOverDialog::setReason(const Reason &reason)
{
    switch (reason) {
    case Reason::playerDiedFromWumpus:
        ui->mGameOverLabel->setText(playerKilledByWumpusText());
        break;
    case Reason::playerDiedFromPit:
        ui->mGameOverLabel->setText(playerKilledByPitText());
        break;
    case Reason::playerIsOutOfArrows:
        ui->mGameOverLabel->setText(playerOutOfArrowsText());
        break;
    }
    update();
}

QString GameOverDialog::playerKilledByWumpusText() const
{
    return tr("You got eaten by the Wumpus!");
}

QString GameOverDialog::playerKilledByPitText() const
{
    return tr("You felt into a bottomless pit!");
}

QString GameOverDialog::playerOutOfArrowsText() const
{
    return tr("You ran out of arrows!");
}
