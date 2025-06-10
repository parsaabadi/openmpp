--
-- create model tables: SM1
-- model digest:        db37c5704473ae83fea0a4e8d68a4804
-- script created:      2025-06-01 18:51:19.092
--

--
-- create model input parameters
--
CREATE TABLE IF NOT EXISTS AuditThreshold_p564b4d28 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS AuditThreshold_w564b4d28 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS EarningsNonZeroProportion_p14a04d8a (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS EarningsNonZeroProportion_w14a04d8a (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS EarningsScaleFactor_p648c9f79 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS EarningsScaleFactor_w648c9f79 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS EarningsSigma_pb7764537 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS EarningsSigma_wb7764537 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS GuaranteedAnnualIncome_p35cf57f7 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS GuaranteedAnnualIncome_w35cf57f7 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS HighIncomeThreshold_p26d4f8f8 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS HighIncomeThreshold_w26d4f8f8 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS MortalityHazard_pf05190dd (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS MortalityHazard_wf05190dd (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS RegionDistribution_p961ffc70 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS RegionDistribution_w961ffc70 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS SE_EarningsNonZeroProportion_p1265a70f (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SE_EarningsNonZeroProportion_w1265a70f (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SE_EarningsScaleFactor_pa7c55617 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SE_EarningsScaleFactor_wa7c55617 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SE_EarningsSigma_pa08cbe10 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SE_EarningsSigma_wa08cbe10 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationCases_p8b4bccb7 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationCases_w8b4bccb7 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_p3df984c3 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_w3df984c3 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));

--
-- create model output tables and views
--
CREATE TABLE IF NOT EXISTS ExampleTable_a8121c486 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id));
CREATE TABLE IF NOT EXISTS ExampleTable_v8121c486 (run_id INT NOT NULL, expr_id SMALLINT NULL, expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id));
CREATE VIEW IF NOT EXISTS ExampleTable_d8121c486 AS WITH va1 AS (SELECT run_id, sub_id, acc_value FROM ExampleTable_a8121c486 WHERE acc_id = 1), va2 AS (SELECT run_id, sub_id, acc_value FROM ExampleTable_a8121c486 WHERE acc_id = 2) SELECT A.run_id, A.sub_id, A.acc_value AS "acc0", A1.acc_value AS "acc1", A2.acc_value AS "acc2", ( A.acc_value ) AS "Expr0", ( A1.acc_value ) AS "Expr1", ( A2.acc_value ) AS "Expr2" FROM ExampleTable_a8121c486 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id) INNER JOIN va2 A2 ON (A2.run_id = A.run_id AND A2.sub_id = A.sub_id) WHERE A.acc_id = 0;

