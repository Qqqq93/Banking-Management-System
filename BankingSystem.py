class Account:
    def __init__(self, account_number, owner_name, balance):
        self.account_number = account_number
        self.owner_name = owner_name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            return f"Deposited ${amount}. New balance: ${self.balance}"
        else:
            return "Invalid deposit amount."

    def withdraw(self, amount):
        if amount > 0 and amount <= self.balance:
            self.balance -= amount
            return f"Withdrew ${amount}. New balance: ${self.balance}"
        else:
            return "Invalid withdrawal amount or insufficient balance."

    def get_balance(self):
        return f"Account balance for {self.owner_name}: ${self.balance}"

    def __str__(self):
        return f"Account Number: {self.account_number}\nOwner: {self.owner_name}\nBalance: ${self.balance}"


class Bank:
    def __init__(self):
        self.accounts = {}

    def create_account(self, account_number, owner_name, initial_balance):
        if account_number not in self.accounts:
            account = Account(account_number, owner_name, initial_balance)
            self.accounts[account_number] = account
            return f"Account created for {owner_name} with account number {account_number}."
        else:
            return "Account with that account number already exists."

    def get_account(self, account_number):
        if account_number in self.accounts:
            return str(self.accounts[account_number])
        else:
            return "Account not found."

    def deposit(self, account_number, amount):
        if account_number in self.accounts:
            return self.accounts[account_number].deposit(amount)
        else:
            return "Account not found."

    def withdraw(self, account_number, amount):
        if account_number in self.accounts:
            return self.accounts[account_number].withdraw(amount)
        else:
            return "Account not found."

    def get_balance(self, account_number):
        if account_number in self.accounts:
            return self.accounts[account_number].get_balance()
        else:
            return "Account not found."

def main():
    bank = Bank()
    while True:
        print("\nBanking Management System")
        print("1. Create Account")
        print("2. Get Account Info")
        print("3. Deposit")
        print("4. Withdraw")
        print("5. Quit")
        choice = input("Enter your choice: ")

        if choice == "1":
            account_number = input("Enter account number: ")
            owner_name = input("Enter owner's name: ")
            initial_balance = float(input("Enter initial balance: "))
            result = bank.create_account(account_number, owner_name, initial_balance)
            print(result)

        elif choice == "2":
            account_number = input("Enter account number: ")
            print(bank.get_account(account_number))

        elif choice == "3":
            account_number = input("Enter account number: ")
            amount = float(input("Enter the amount to deposit: "))
            result = bank.deposit(account_number, amount)
            print(result)

        elif choice == "4":
            account_number = input("Enter account number: ")
            amount = float(input("Enter the amount to withdraw: "))
            result = bank.withdraw(account_number, amount)
            print(result)

        elif choice == "5":
            print("Goodbye!")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
