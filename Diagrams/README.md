# UML Diagram description

## Warstwa połączenia

IConnector[Pattern: facade]  -> Interface po którym dziedziczą takie klasy jak MockConnector, FileConnector oraz DBConnector. Ukrywa połączenie do warstwu danych(plik, DB) co ułatwia implementację poprawek.

MockConnector - Specjalizacja IConnector dla warstwy dostępu vector<Student>;

FileConnector - Specjalizacja IConnector dla warstwy dostępu do pliku

DBConnector - Specjalizacja IConnector dla warstwy dostępu do bazy danych ( nazwa jest ogólna np dla MySQL będzie to MYSQLConnector)

```
notes:
-- Warstwa połączenia do warstwu danych może być pominięta jeśli zaimplementujemy ją bezpośrednio w implementacji Reposytorium.
```

## Warstwa dostępu do do danych

IRepository[Pattern: Repository]  -> Główny interface określający podstawowe operacje na warstwie danych.

IUserRepository  -> specjalizacja IRepository dla pobierania danych użytkownika.

UserRepositoryImp -> Implementacja IUserRepository dla wybranego dostępu typu połączenia (DB, file)


## Warstwa API

CRUUser ->  Klasa posiadająca zbiór funkcji dla dodawania użytkownika, usuwania użytkownia i modyfikacji użytkownika.
-- addUser() - dodaje użytkownika do listy m_Users.
-- reniveUser() - usuwa użytkownika z listy m_Users.
-- getUser i GetAll - wyświetla wszystkich użytkowników na z listy m_Users.

searchUser -> Klasa posiadająca zbiór funkcji dla dodawania użytkowników, usuwania użytkowników i modyfikacji użytkowników.
-- Users wyświetla wszystkich użytkowników spełniających kryteria.
-- allUsers - wyświelta wszystkich użytkowników na bazie.

CreateUser -> API Spacjalizacja CRUUser dla tworzenia użytkowników.
-- Save() zapisuje użytkownika/ów do bazy.
 
RemoveUser -> API Spacjalizacja CRUUser dla usuwania użytkowników.
-- Save() usuwa użytkownika/ów z bazy.

UpdateUser -> API Spacjalizacja CRUUser dla aktualizacji danych użytkowników.
-- Save() aktualizuje użytkownika/ów.


## contenery danych

User - posiada informacje o danych użytkownika i weryfikuje ich poprawność.

## Diagram Bugs: 

-- searchUser powinien powiązany z UserRepositoryImp a nie jak jest na diagramie z CRUUser.
-- Brak IUserRepository.
-- UserRepositoryImp w diagramie nazuwa się UserRepository.
-- Brak IConnector. 

