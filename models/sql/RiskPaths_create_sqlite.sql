--
-- create model tables: RiskPaths
-- model digest:        d976aa2fb999f097468bb2ea098c4daf
-- script created:      2025-06-01 18:50:02.483
--

--
-- create model input parameters
--
CREATE TABLE IF NOT EXISTS AgeBaselineForm1_pb3006441 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS AgeBaselineForm1_wb3006441 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS AgeBaselinePreg1_p51c16bfc (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS AgeBaselinePreg1_w51c16bfc (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS CanDie_pa335fe93 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value SMALLINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS CanDie_wa335fe93 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value SMALLINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS ProbMort_p8ce459f6 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS ProbMort_w8ce459f6 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS SeparationDurationBaseline_p655998e0 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS SeparationDurationBaseline_w655998e0 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS SimulationCases_p8b4bccb7 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationCases_w8b4bccb7 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_p3df984c3 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_w3df984c3 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS UnionDurationBaseline_p038d4b5e (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS UnionDurationBaseline_w038d4b5e (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS UnionStatusPreg1_pc4e9805e (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS UnionStatusPreg1_wc4e9805e (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id, dim0));

--
-- create model output tables and views
--
CREATE TABLE IF NOT EXISTS T01_LifeExpectancy_af4cddad0 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id));
CREATE TABLE IF NOT EXISTS T01_LifeExpectancy_vf4cddad0 (run_id INT NOT NULL, expr_id SMALLINT NULL, expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id));
CREATE VIEW IF NOT EXISTS T01_LifeExpectancy_df4cddad0 AS WITH va1 AS (SELECT run_id, sub_id, acc_value FROM T01_LifeExpectancy_af4cddad0 WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.acc_value AS "acc0", A1.acc_value AS "acc1", ( A.acc_value ) AS "Expr0", ( A1.acc_value ) AS "Expr1", ( (A1.acc_value / A.acc_value) ) AS "Expr2" FROM T01_LifeExpectancy_af4cddad0 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T02_TotalPopulationByYear_af4f55780 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T02_TotalPopulationByYear_vf4f55780 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T02_TotalPopulationByYear_df4f55780 AS WITH va1 AS (SELECT run_id, sub_id, dim0, acc_value FROM T02_TotalPopulationByYear_af4f55780 WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( A.acc_value ) AS "Expr0", ( A1.acc_value ) AS "Expr1" FROM T02_TotalPopulationByYear_af4f55780 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T03_FertilityByAge_a5dc77583 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T03_FertilityByAge_v5dc77583 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T03_FertilityByAge_d5dc77583 AS WITH va1 AS (SELECT run_id, sub_id, dim0, acc_value FROM T03_FertilityByAge_a5dc77583 WHERE acc_id = 1), va2 AS (SELECT run_id, sub_id, dim0, acc_value FROM T03_FertilityByAge_a5dc77583 WHERE acc_id = 2) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.acc_value AS "acc0", A1.acc_value AS "acc1", A2.acc_value AS "acc2", ( (A.acc_value / A1.acc_value) ) AS "Expr0", ( (A.acc_value / A2.acc_value) ) AS "Expr1" FROM T03_FertilityByAge_a5dc77583 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0) INNER JOIN va2 A2 ON (A2.run_id = A.run_id AND A2.sub_id = A.sub_id AND A2.dim0 = A.dim0) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T04_FertilityRatesByAgeGroup_a1f93417b (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS T04_FertilityRatesByAgeGroup_v1f93417b (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS T04_FertilityRatesByAgeGroup_d1f93417b AS WITH va1 AS (SELECT run_id, sub_id, dim0, dim1, acc_value FROM T04_FertilityRatesByAgeGroup_a1f93417b WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "Expr0" FROM T04_FertilityRatesByAgeGroup_a1f93417b A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0 AND A1.dim1 = A.dim1) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T05_CohortFertility_a284c576e (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id));
CREATE TABLE IF NOT EXISTS T05_CohortFertility_v284c576e (run_id INT NOT NULL, expr_id SMALLINT NULL, expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id));
CREATE VIEW IF NOT EXISTS T05_CohortFertility_d284c576e AS WITH va1 AS (SELECT run_id, sub_id, acc_value FROM T05_CohortFertility_a284c576e WHERE acc_id = 1), va2 AS (SELECT run_id, sub_id, acc_value FROM T05_CohortFertility_a284c576e WHERE acc_id = 2) SELECT A.run_id, A.sub_id, A.acc_value AS "acc0", A1.acc_value AS "acc1", A2.acc_value AS "acc2", ( (A.acc_value / A1.acc_value) ) AS "Expr0", ( (1 - (A1.acc_value / A2.acc_value)) ) AS "Expr1", ( (A1.acc_value / A2.acc_value) ) AS "Expr2" FROM T05_CohortFertility_a284c576e A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id) INNER JOIN va2 A2 ON (A2.run_id = A.run_id AND A2.sub_id = A.sub_id) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T06_BirthsByUnion_a7bb3113c (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T06_BirthsByUnion_v7bb3113c (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T06_BirthsByUnion_d7bb3113c AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM T06_BirthsByUnion_a7bb3113c A WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T07_FirstUnionFormation_a02fc7f1d (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T07_FirstUnionFormation_v02fc7f1d (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T07_FirstUnionFormation_d02fc7f1d AS WITH va1 AS (SELECT run_id, sub_id, dim0, acc_value FROM T07_FirstUnionFormation_a02fc7f1d WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "Expr0" FROM T07_FirstUnionFormation_a02fc7f1d A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0) WHERE A.acc_id = 0;

