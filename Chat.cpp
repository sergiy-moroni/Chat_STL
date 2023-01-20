#include "Chat.h"

Chat::Chat() {};
Chat::~Chat() {};

void Chat::start() {
	std::cout << "Добро пожаловать в чат!" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Количество зарегестрированных пользователей: " << size(Userslist) << std::endl;
		std::cout << "Введите желаемое действие: \n1 - для входа.\n2 - для регистрации нового пользователя \n0 - для выхода из чата" << std::endl;
		int c;
		std::cin >> c;
		if (c != 0 && c != 2 && c != 1)
		{
			std::cout << "Неверный ВВОД!" << std::endl;
			continue;
		}
		// регистрация нового пользователя
		if (c == 2)
		{
			CreateNewUser();
			continue;
		}
		if (c == 0) {
			break;
		}

		//вход по логину ипаролю
		if (c == 1)
		{
			std::string log;
			std::string pas;
			std::cout << "Введите логин: ";
			std::cin >> log;
			std::cout << "Введите пароль: ";
			std::cin >> pas;
			if (FindUser(log, pas))
			{
				while (true)
				{
					std::string h;
					std::string message;
					inuser = true;
					std::cout << std::endl;
					//выбор пользователем желаемого действия
					std::cout << "Введите номер желаемого действия: " << std::endl;
					std::cout << "1 - Прочитать все входящие сообщения" << std::endl;
					std::cout << "2 - Написать сообщение другому пользователю" << std::endl;
					std::cout << "0 - Выйти" << std::endl;
					int c = 0;
					std::cin >> c;
					if (c == 0)
					{
						std::cout << "Досвидания, " << Userslist[user_islogin].GetName() << "!" << std::endl;
						break;
					}
					switch (c)
					{

					case 1:
						if (Userslist[user_islogin].IsEmpty())
						{
							std::cout << "У вас еще нет входящих сообщений!" << std::endl;
						}
						else
						{
							Userslist[user_islogin].PrintMessages();
						}
						break;

					case 2:
						std::cout << "Введите ИМЯ пользователя которому хотите отправить сообщение: " << std::endl << std::endl;
						PrintUsersNames();
						std::cout << "\"all\"  - чтобы отправиль сообщение всем пользователям чата:" << std::endl << std::endl;
						std::cin >> h;
						if (h == "all")
						{// отправка сообщения всем пользователям чата
							std::cout << "Введите текст сообщения: " << std::endl;
							std::cout << std::endl;
							std::getline(std::cin, message, '\n');
							std::getline(std::cin, message, '\n');

							Message<std::string> mes(Userslist[user_islogin].GetName(), message);
							for (int i = 0; i < size(Userslist); ++i)
							{
								Userslist[i].Setmessage(mes);
							}
							std::cout << "Сообщение разослано всем пользователям!" << std::endl;
						}
						else
						{
							int t = -1;
							t = FindUserinUserslist(h);//отправка сообщения по введенному имени полльзователя

							if (t == (-1))
							{
								std::cout << "Пользователь с данным именем не найден" << std::endl;
							}
							else
							{
								std::cout << "Введите текст сообщения: " << std::endl;
								std::cout << std::endl;
								std::getline(std::cin, message, '\n');
								std::getline(std::cin, message, '\n');
								Message<std::string> mes(Userslist[user_islogin].GetName(), message);
								Userslist[FindUserinUserslist(h)].Setmessage(mes);
								std::cout << "Сообщение отправлено!" << std::endl;
							}
						}
						break;
					default:
						std::cout << "Неверный ВВОД!" << std::endl;
						break;
					}
				}
			}
			else
			{
				inuser = false;
			}
		}
	}
}

bool Chat::FindUser(const std::string& login, const std::string& pass)
{
	int i = 0;
	bool j = false;

	for (std::vector<User>::iterator it = Userslist.begin(); it != Userslist.end(); ++it)
	{
		std::string l = it->Getlog();
		std::string k = it->Getpass();
		if (login == l && pass == k)
		{
			std::cout << std::endl << "Здравствуйте, " << it->GetName() << "!" << std::endl << std::endl;
			user_islogin = i;
			j = true;
			return j;
		}
		else
		{
			i++;
		}
	}
	if (j == false) {
		std::cout << "\nНеверный логин или пароль" << std::endl;
	}
	return j;
}

bool Chat::FindLogin(const std::string& login)
{
	bool j = false;
	for (std::vector<User>::iterator it = Userslist.begin(); it != Userslist.end(); ++it)
	{
		if (it->Getlog() == login)
		{
			j = true;
			return j;
		}
	}return j;
}

//метод создания нового пользователя чата
void Chat::CreateNewUser()
{
	std::cout << "Введите данные для регистрации" << std::endl;
	std::cout << "Введите имя пользователя: ";
	std::string name;
	std::string login;
	std::string pass;
	std::getline(std::cin, name, '\n');
	std::getline(std::cin, name, '\n');
	std::cout << "Введите логин для входа в систему: ";
	bool l = true;
	while (l)
	{
		std::cin >> login;
		if (FindLogin(login))
		{
			std::cout << "Данный логин уже занят выберите другой!" << std::endl;
			std::cout << "Введите логин для входа в систему: ";
		}
		else
		{
			l = false;
		}
	}
	std::cout << "Введите пароль: ";
	std::cin >> pass;
	User U(name, login, pass);
	Userslist.push_back(U);
	std::cout << "Пользователь успешно зарегистрирован!" << std::endl << std::endl;
}

void Chat::PrintUsersNames()
{
	int count = 1;
	for (std::vector<User>::iterator it = Userslist.begin(); it != Userslist.end(); ++it)
	{
		std::cout << (count++) << ". " << it->GetName() << std::endl;
	}
}

//метод возвращает номер пользователя в списке Userlist по имени
int Chat::FindUserinUserslist(const std::string& name)
{
	int index = 0;
	for (std::vector<User>::iterator it = Userslist.begin(); it != Userslist.end(); ++it)
	{
		if (it->GetName() == name)
		{
			return index;
		}
		else
		{
			index++;
		}
	}
	return -1;
}
