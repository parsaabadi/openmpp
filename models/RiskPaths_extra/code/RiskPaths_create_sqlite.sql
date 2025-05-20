--
-- create model tables: RiskPaths
-- model digest:        2c0eef92573bbab8afa93e6eac19c1c9
-- script created:      2025-05-15 14:47:08.459
--

--
-- create model input parameters
--

--
-- create model output tables and views
--
CREATE TABLE IF NOT EXISTS T01_LifeExpectancy_a115922f6 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id));
CREATE TABLE IF NOT EXISTS T01_LifeExpectancy_v115922f6 (run_id INT NOT NULL, expr_id SMALLINT NULL, expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id));
CREATE VIEW IF NOT EXISTS T01_LifeExpectancy_d115922f6 AS WITH va1 AS (SELECT run_id, sub_id, acc_value FROM T01_LifeExpectancy_a115922f6 WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.acc_value AS "acc0", A1.acc_value AS "acc1", ( A.acc_value ) AS "Total_simulated_cases", ( A1.acc_value ) AS "Total_duration", ( (A1.acc_value / A.acc_value) ) AS "Life_expectancy" FROM T01_LifeExpectancy_a115922f6 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T02_TotalPopulationByYear_ad90dee6f (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T02_TotalPopulationByYear_vd90dee6f (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T02_TotalPopulationByYear_dd90dee6f AS WITH va1 AS (SELECT run_id, sub_id, dim0, acc_value FROM T02_TotalPopulationByYear_ad90dee6f WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Age", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( A.acc_value ) AS "Population_start_of_year", ( A1.acc_value ) AS "Average_population_in_year" FROM T02_TotalPopulationByYear_ad90dee6f A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T03_FertilityByAge_a558a5484 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T03_FertilityByAge_v558a5484 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T03_FertilityByAge_d558a5484 AS WITH va1 AS (SELECT run_id, sub_id, dim0, acc_value FROM T03_FertilityByAge_a558a5484 WHERE acc_id = 1), va2 AS (SELECT run_id, sub_id, dim0, acc_value FROM T03_FertilityByAge_a558a5484 WHERE acc_id = 2) SELECT A.run_id, A.sub_id, A.dim0 AS "Age", A.acc_value AS "acc0", A1.acc_value AS "acc1", A2.acc_value AS "acc2", ( (A.acc_value / A1.acc_value) ) AS "First_birth_rate_all_women", ( (A.acc_value / A2.acc_value) ) AS "First_birth_rate_woman_at_risk" FROM T03_FertilityByAge_a558a5484 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0) INNER JOIN va2 A2 ON (A2.run_id = A.run_id AND A2.sub_id = A.sub_id AND A2.dim0 = A.dim0) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T04_FertilityRatesByAgeGroup_abd71b745 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS T04_FertilityRatesByAgeGroup_vbd71b745 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS T04_FertilityRatesByAgeGroup_dbd71b745 AS WITH va1 AS (SELECT run_id, sub_id, dim0, dim1, acc_value FROM T04_FertilityRatesByAgeGroup_abd71b745 WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Age_interval", A.dim1 AS "Union_Status", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "Fertility" FROM T04_FertilityRatesByAgeGroup_abd71b745 A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0 AND A1.dim1 = A.dim1) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T05_CohortFertility_a446056ef (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id));
CREATE TABLE IF NOT EXISTS T05_CohortFertility_v446056ef (run_id INT NOT NULL, expr_id SMALLINT NULL, expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id));
CREATE VIEW IF NOT EXISTS T05_CohortFertility_d446056ef AS WITH va1 AS (SELECT run_id, sub_id, acc_value FROM T05_CohortFertility_a446056ef WHERE acc_id = 1), va2 AS (SELECT run_id, sub_id, acc_value FROM T05_CohortFertility_a446056ef WHERE acc_id = 2) SELECT A.run_id, A.sub_id, A.acc_value AS "acc0", A1.acc_value AS "acc1", A2.acc_value AS "acc2", ( (A.acc_value / A1.acc_value) ) AS "Av_age_at_1st_pregnancy", ( (1 - (A1.acc_value / A2.acc_value)) ) AS "Childlessness", ( (A1.acc_value / A2.acc_value) ) AS "Percent_one_child" FROM T05_CohortFertility_a446056ef A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id) INNER JOIN va2 A2 ON (A2.run_id = A.run_id AND A2.sub_id = A.sub_id) WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T06_BirthsByUnion_a55ef4bd4 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T06_BirthsByUnion_v55ef4bd4 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T06_BirthsByUnion_d55ef4bd4 AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Union_Status_at_pregnancy", A.acc_value AS "acc0", ( A.acc_value ) AS "Number_of_pregnancies" FROM T06_BirthsByUnion_a55ef4bd4 A WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS T07_FirstUnionFormation_a4ab7471b (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0));
CREATE TABLE IF NOT EXISTS T07_FirstUnionFormation_v4ab7471b (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0));
CREATE VIEW IF NOT EXISTS T07_FirstUnionFormation_d4ab7471b AS WITH va1 AS (SELECT run_id, sub_id, dim0, acc_value FROM T07_FirstUnionFormation_a4ab7471b WHERE acc_id = 1) SELECT A.run_id, A.sub_id, A.dim0 AS "Age_group", A.acc_value AS "acc0", A1.acc_value AS "acc1", ( (A.acc_value / A1.acc_value) ) AS "First_union_formation_risk" FROM T07_FirstUnionFormation_a4ab7471b A INNER JOIN va1 A1 ON (A1.run_id = A.run_id AND A1.sub_id = A.sub_id AND A1.dim0 = A.dim0) WHERE A.acc_id = 0;

