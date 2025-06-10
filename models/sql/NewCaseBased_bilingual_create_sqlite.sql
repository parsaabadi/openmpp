--
-- create model tables: NewCaseBased_bilingual
-- model digest:        2a78a09cb2b597fa25531dbdb147269a
-- script created:      2025-06-01 18:49:25.421
--

--
-- create model input parameters
--
CREATE TABLE IF NOT EXISTS MortalityHazard_pf05190dd (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS MortalityHazard_wf05190dd (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationCases_p8b4bccb7 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationCases_w8b4bccb7 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_p3df984c3 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_w3df984c3 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));

--
-- create model output tables and views
--
CREATE TABLE IF NOT EXISTS DurationOfLife_ad7fa6899 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id));
CREATE TABLE IF NOT EXISTS DurationOfLife_vd7fa6899 (run_id INT NOT NULL, expr_id SMALLINT NULL, expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id));
CREATE VIEW IF NOT EXISTS DurationOfLife_dd7fa6899 AS WITH va1 AS (SELECT run_id, sub_id, acc_value FROM DurationOfLife_ad7fa6899 WHERE acc_id = 1), va2 AS (SELECT run_id, sub_id, acc_value FROM DurationOfLife_ad7fa6899 WHERE acc_id = 2), va3 AS (SELECT run_id, sub_id, acc_value FROM DurationOfLife_ad7fa6899 WHERE acc_id = 3) SELECT A.run_id, A.sub_id, A.acc_value AS "acc0", A1.acc_value AS "acc1", A2.acc_value AS "acc2", A3.acc_value AS "acc3", ( A.acc_value ) AS "Expr0", ( A1.acc_value ) AS "Expr1", ( A2.acc_value ) AS "Expr2", ( (A3.acc_value / A.acc_value) ) AS "Expr3" FROM DurationOfLife_ad7fa6899 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id) INNER JOIN va2 A2 ON (A2.run_id = A.run_id AND A2.sub_id = A.sub_id) INNER JOIN va3 A3 ON (A3.run_id = A.run_id AND A3.sub_id = A.sub_id) WHERE A.acc_id = 0;

