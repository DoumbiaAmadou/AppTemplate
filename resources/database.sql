CREATE TABLE utilisateur
(
    id INT PRIMARY KEY NOT NULL,
    nom VARCHAR(100),
    prenom VARCHAR(100),
    email VARCHAR(255),
    date_naissance DATE,
    pays VARCHAR(255),
    ville VARCHAR(255),
    code_postal VARCHAR(5),
    nombre_achat INT
);

CREATE TABLE `dbVersion` ( `id` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
`version` varchar(20),
`dateVersion` datetime )
