-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : jeu. 27 fév. 2020 à 17:07
-- Version du serveur :  10.4.11-MariaDB
-- Version de PHP : 7.4.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `naavi_pge`
--

-- --------------------------------------------------------

--
-- Structure de la table `images`
--

CREATE TABLE `images` (
  `id` int(10) NOT NULL,
  `cheminImages` varchar(100) NOT NULL,
  `cheminPointsdePassages` varchar(100) NOT NULL,
  `id_mission` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `mission`
--

CREATE TABLE `mission` (
  `id` int(10) NOT NULL,
  `users` varchar(10) NOT NULL,
  `dates` varchar(30) NOT NULL,
  `pylones` varchar(30) NOT NULL,
  `lieudit` varchar(100) NOT NULL,
  `lat` varchar(10) NOT NULL,
  `lon` varchar(10) NOT NULL,
  `deg` varchar(10) NOT NULL,
  `pluie` varchar(10) NOT NULL,
  `vent` varchar(10) NOT NULL,
  `type` varchar(50) NOT NULL,
  `resultat` varchar(20) NOT NULL,
  `hauteur` varchar(10) NOT NULL,
  `lat_atterissage` varchar(10) NOT NULL,
  `lon_atterissage` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `mission`
--

INSERT INTO `mission` (`id`, `users`, `dates`, `pylones`, `lieudit`, `lat`, `lon`, `deg`, `pluie`, `vent`, `type`, `resultat`, `hauteur`, `lat_atterissage`, `lon_atterissage`) VALUES
(1, '1', '20 février 2020  11:45', 'Pylône détecté : XXXX', 'Ramonville-Saint-Agne', '43', '1.5', '12 °C', '71%', '03', 'Few clouds', 'Aucune erreur', '30', 'pasencore', 'pasencore'),
(2, '1', '20 février 2020  13:33', 'Pylône détecté : XXXX', 'Ramonville-Saint-Agne', '43.5', '1.5', '15 °C', '58%', '03', 'Clear sky', 'Aucune erreur', '30', 'pasencore', 'pasencore'),
(3, '1', '20 février 2020  13:48', 'Pylône détecté : XXXX', 'Ramonville-Saint-Agne', '45', '1.5', '16 °C', '48%', '01', 'Clear sky', 'Aucune erreur', '30', 'pasencore', 'pasencore'),
(4, '1', '21 février 2020  11:23', 'Pylône détecté : XXXX', 'Ramonville-Saint-Agne', '43.5', '1.5', '9 °C', '87%', '02', 'Light intensity drizzle rain', 'Aucune erreur', '320', 'pasencore', 'pasencore'),
(5, '1', '25 février 2020  14:23', 'Pylône détecté : XXXX', 'Ramonville-Saint-Agne', '43', '1.46', '13 °C', '67%', '10', 'Broken clouds', 'Aucune erreur', '30', 'pasencore', 'pasencore'),
(6, '1', '25 février 2020  15:30', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '43', '1.46', '14 °C', '67%', '09', 'Broken clouds', 'Aucune erreur', '30', 'pasencore', 'pasencore'),
(7, '1', '25 février 2020  15:30', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '43.5', '1', '14 °C', '67%', '09', 'Broken clouds', 'Aucune erreur', '30', 'pasencore', 'pasencore'),
(8, '1', '25 février 2020  20:50', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '43.55', '1.46', '9 °C', '76%', '10', 'Few clouds', 'Aucune erreur', '1', 'pasencore', 'pasencore'),
(9, '2', '25 février 2020  23:47', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '43.5656', '1.436578', '9 °C', '81%', '07', 'Light rain', 'Aucune erreur', '1', 'pasencore', 'pasencore'),
(10, '2', '25 février 2020  23:47', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '10', '10', '9 °C', '81%', '07', 'Light rain', 'Aucune erreur', '10', 'pasencore', 'pasencore'),
(11, '2', '26 février 2020  00:27', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '10', '10', '8 °C', '81%', '07', 'Light rain', 'aucune erreur', '10', 'pasencore', 'pasencore'),
(12, '2', '26 février 2020  00:28', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '10', '10', '8 °C', '81%', '07', 'Light rain', 'aucune erreur', '10', 'pasencore', 'pasencore'),
(13, '2', '26 février 2020  08:37', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '43.55656', '1.467759', '7 °C', '87%', '09', 'Light rain', 'aucune erreur', '1', 'pasencore', 'pasencore'),
(14, '2', '26 février 2020  10:56', 'Pylône détecté : DemoV1', 'Ramonville-Saint-Agne', '43.55656', '1.437759', '7 °C', '87%', '09', 'Heavy intensity drizzle rain', 'aucune erreur', '1', 'pasencore', 'pasencore');

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `id` int(10) NOT NULL,
  `identification` varchar(50) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `prenom` varchar(50) NOT NULL,
  `hash` varchar(100) NOT NULL,
  `salt` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`id`, `identification`, `nom`, `prenom`, `hash`, `salt`) VALUES
(1, 'admin', 'admin', 'admin', '$5$rounds=5000$youShallNotPassa$kSu74ICIgSLaMLVSpJW3d.bnD8ekEkcy49C2YppQHFD', '$5$rounds=5000$youShallNotPassadmin$'),
(2, 'MarcelC', 'Campagnole', 'Marcel', '$5$rounds=5000$youShallNotPassC$8/8zx2BgbQc5IlGzPMjUYBTORXegu09kqjkh5DUtqmC', '$5$rounds=5000$youShallNotPassCampagnole$');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `images`
--
ALTER TABLE `images`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `mission`
--
ALTER TABLE `mission`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `identification` (`identification`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `images`
--
ALTER TABLE `images`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `mission`
--
ALTER TABLE `mission`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
