#include <iostream>
#include <Windows.h>


using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double balance, double interestRate) {
        this->accountNumber = accNumber;
        this->balance = balance;
        this->interestRate = interestRate;
    }

    void deposit() {
        double count;
        cout << "Выберите сумму, которую хотели бы внести: ";
        while (!(cin >> count)) {
            cout << "Ошибка ввода. Введите число: ";
        }
        this->balance += count;
        cout << "Деньги были успешно зачислены на счёт!" << endl;
    }

    void withdraw() {
        double count;
        cout << "Сколько вы хотели бы снять со счёта? ";
        while (!(cin >> count)) {
            cout << "Ошибка ввода. Введите число: ";
        }
        if (balance >= count) {
            balance -= count;
            cout << "Деньги были успешно сняты со счёта!" << endl;
        }
        else {
            cout << "Недостаточно средств на счёте!" << endl;
        }
    }

    double getBalance() {
        cout << "Ваш текущий баланс: " << balance << endl;
        return balance;
    }

    double getInterest() {
        double NewInterest = this->balance * this->interestRate * (1.0 / 12);
        cout << "За месяц вы получите: " << NewInterest << endl;
        return NewInterest;
    }

    void setInterestRate() {
        this->interestRate = this->balance * 7 * (1.0 / 12);
        cout << "Процентная ставка была обновлена до 7%, в следующие разы ваш процентный доход будет составлять: " << this->interestRate << endl;
    }
    int getAccountNumber() {
        cout << "Номер вашего счёта: " << this->accountNumber << endl;
        return accountNumber;
    }

    friend bool trf(BankAccount& Account1, BankAccount& Account2, double count) { 
        if (count > 0 && count <= Account1.balance) {
            Account1.balance -= count;
            Account2.balance += count;
            cout << "Перевод был успешно выполнен! " << count << " От " << Account1.accountNumber << " Для " << Account2.accountNumber << endl;
            return true;
        }
        else {
            cout << "Ошибка! Перевод не был выполнен, проверьте ваш баланс или обратитесь в поддержку." << endl;
            return false;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    BankAccount Account1(120675, 50000, 0.0);
    BankAccount Account2(450732, 10000, 0.0);
    int vibor;

    while (true)
    {
        cout << "Добро пожаловать в ваш банк на электронных колёсах! Выберите операцию: \n";
        cout << "1. Пополнить счёт.\n";
        cout << "2. Снять средства со счёта. \n";
        cout << "3. Узнать баланс счёта.\n";
        cout << "4. Рассчитать средства на основе процентной ставки.\n";
        cout << "5. Обновить процентную ставку.\n";
        cout << "6. Узнать номер банковского счёта.\n";
        cout << "7. Совершить перевод средств на другой счёт.\n";
        cout << "8. Я хочу перестать тратить деньги, пока.\n";
        if (!(cin >> vibor)) {
            cout << "Ошибка! Введите номер операции." << endl;
            break;
           


        }
        else if (vibor == 1) {
            Account1.deposit();
        }
        else if (vibor == 2) {
            Account1.withdraw();
        }
        else if (vibor == 3) {
            Account1.getBalance();
        }
        else if (vibor == 4) {
            Account1.getInterest();
        }
        else if (vibor == 5) {
            Account1.setInterestRate();
        }
        else if (vibor == 6) {
            Account1.getAccountNumber();
        }
        else if (vibor == 7) {
            double count;
            cout << "Введите сумму для перевода: ";
            while (!(cin >> count)) {
                cout << "Ошибка ввода. Введите число: ";
            }
            trf(Account1, Account2, count);
            cout << "Перевод был выполнен успешно.\n";
        }
        else if (vibor == 8) {
            cout << "Прощайте, приходите ещё тратить ваши деньги!\n";
            break;
        }
        else {
            cout << "Ошибка! Введите номер из предложенных операций.\n";
        }


        
    }

    return 0;
}
    

