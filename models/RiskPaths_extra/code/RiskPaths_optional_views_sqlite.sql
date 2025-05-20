--
-- compatibility views for model: RiskPaths
-- model digest:   2c0eef92573bbab8afa93e6eac19c1c9
-- script created: 2025-05-15 14:47:08.459
--
-- Dear user:
--   this part of database is optional and NOT used by openM++
--   if you want it for any reason please enjoy else just ignore it
-- Or other words:
--   if you don't know what this is then you don't need it
--

--
-- input parameters compatibility views
--

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS T01_LifeExpectancy AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM T01_LifeExpectancy_v115922f6 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');
CREATE VIEW IF NOT EXISTS T02_TotalPopulationByYear AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T02_TotalPopulationByYear_vd90dee6f S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');
CREATE VIEW IF NOT EXISTS T03_FertilityByAge AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T03_FertilityByAge_v558a5484 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');
CREATE VIEW IF NOT EXISTS T04_FertilityRatesByAgeGroup AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM T04_FertilityRatesByAgeGroup_vbd71b745 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');
CREATE VIEW IF NOT EXISTS T05_CohortFertility AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM T05_CohortFertility_v446056ef S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');
CREATE VIEW IF NOT EXISTS T06_BirthsByUnion AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T06_BirthsByUnion_v55ef4bd4 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');
CREATE VIEW IF NOT EXISTS T07_FirstUnionFormation AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T07_FirstUnionFormation_v4ab7471b S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '2c0eef92573bbab8afa93e6eac19c1c9');

