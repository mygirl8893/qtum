#ifndef CONTRACTSINFO_H
#define CONTRACTSINFO_H

#include <QWidget>
#include <QStandardItemModel>
#include <walletmodel.h>
#include "transactionrecord.h"
#include <analyzerERC20.h>
#include <libethcore/ABI.h>
#include "base58.h"

#include "calldialog.h"

namespace Ui {
class ContractsInfo;
}

class ContractsInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ContractsInfo(WalletModel *_walletModel, QWidget *parent = 0);
    ~ContractsInfo();

    void setWalletModel(WalletModel *walletModel);

public Q_SLOTS:

    void updateInfo();
    void contractSelected(QModelIndex index);
    void tokenSelected(QModelIndex index);
    void showWatchDialog();

private:
    void updateContractModelAndTokenModel(CContractInfo& info, TransactionStatus::Status status);
    void updateContractsToDBWallet(CContractInfo& info);
    void updateConfirmContracts(CContractInfo& info);
    void showContractInterface(QString address);
    
    std::vector<ContractMethod> createListMethods(CContractInfo contractInfo);

    WalletModel *walletModel;
    TransactionTableModel *txTableModel;
    Ui::ContractsInfo *ui;
};

#endif // CONTRACTSINFO_H

