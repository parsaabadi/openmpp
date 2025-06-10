--
-- create model tables: OzProjGenX
-- model digest:        1da1caabb11915156f8825253fb7d62d
-- script created:      2025-06-01 18:50:24.518
--

--
-- create model input parameters
--
CREATE TABLE IF NOT EXISTS ImmigrantAgeDist_p55f56410 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS ImmigrantAgeDist_w55f56410 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS IndigenousProportion_p189bb858 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS IndigenousProportion_w189bb858 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS MicroDataOutputFile_p6d28ab86 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value VARCHAR(260) NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS MicroDataOutputFile_w6d28ab86 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value VARCHAR(260) NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS NativeBorn_p81aeb1ac (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS NativeBorn_w81aeb1ac (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS RecentArrival_p6140f8db (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS RecentArrival_w6140f8db (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS RegionAgeSexDistn_pc358a4fc (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, dim2 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1, dim2));
CREATE TABLE IF NOT EXISTS RegionAgeSexDistn_wc358a4fc (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, dim2 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1, dim2));
CREATE TABLE IF NOT EXISTS SimulationCases_p8b4bccb7 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationCases_w8b4bccb7 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_p3df984c3 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_w3df984c3 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS StartPopDistn_pcaf025fb (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS StartPopDistn_wcaf025fb (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1));

--
-- create model output tables and views
--
CREATE TABLE IF NOT EXISTS InitialIndigenous_a64c27595 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS InitialIndigenous_v64c27595 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS InitialIndigenous_d64c27595 AS WITH va1 AS (SELECT run_id, sub_id, dim0, dim1, acc_value FROM InitialIndigenous_a64c27595 WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "Expr0" FROM InitialIndigenous_a64c27595 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0 AND A1.dim1 = A.dim1) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS InitialNativeBorn_a78e403ca (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS InitialNativeBorn_v78e403ca (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS InitialNativeBorn_d78e403ca AS WITH va1 AS (SELECT run_id, sub_id, dim0, dim1, acc_value FROM InitialNativeBorn_a78e403ca WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "Expr0" FROM InitialNativeBorn_a78e403ca A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0 AND A1.dim1 = A.dim1) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS InitialPopCounts_ac107a6da (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS InitialPopCounts_vc107a6da (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS InitialPopCounts_dc107a6da AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM InitialPopCounts_ac107a6da A WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS InitialRecentArrival_a25c09108 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS InitialRecentArrival_v25c09108 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS InitialRecentArrival_d25c09108 AS WITH va1 AS (SELECT run_id, sub_id, dim0, dim1, acc_value FROM InitialRecentArrival_a25c09108 WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "Expr0" FROM InitialRecentArrival_a25c09108 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0 AND A1.dim1 = A.dim1) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS InitialRegion_a77bfb15b (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS InitialRegion_v77bfb15b (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS InitialRegion_d77bfb15b AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM InitialRegion_a77bfb15b A WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS InitialYearsSinceArrival_a44cd422f (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, dim2 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1, dim2));
CREATE TABLE IF NOT EXISTS InitialYearsSinceArrival_v44cd422f (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL, dim2 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1, dim2));
CREATE VIEW IF NOT EXISTS InitialYearsSinceArrival_d44cd422f AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.dim2 AS "Dim2", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM InitialYearsSinceArrival_a44cd422f A WHERE A.acc_id = 0;

