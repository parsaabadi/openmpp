--
-- compatibility views for model: RiskPaths
-- model digest:   d976aa2fb999f097468bb2ea098c4daf
-- script created: 2025-06-01 18:50:02.483
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
CREATE VIEW IF NOT EXISTS AgeBaselineForm1 AS SELECT S.dim0 AS "Dim0", S.param_value AS "Value" FROM AgeBaselineForm1_pb3006441 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS AgeBaselinePreg1 AS SELECT S.dim0 AS "Dim0", S.param_value AS "Value" FROM AgeBaselinePreg1_p51c16bfc S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS CanDie AS SELECT S.param_value AS "Value" FROM CanDie_pa335fe93 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS ProbMort AS SELECT S.dim0 AS "Dim0", S.param_value AS "Value" FROM ProbMort_p8ce459f6 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS SeparationDurationBaseline AS SELECT S.dim0 AS "Dim0", S.param_value AS "Value" FROM SeparationDurationBaseline_p655998e0 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS SimulationCases AS SELECT S.param_value AS "Value" FROM SimulationCases_p8b4bccb7 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS SimulationSeed AS SELECT S.param_value AS "Value" FROM SimulationSeed_p3df984c3 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS UnionDurationBaseline AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.param_value AS "Value" FROM UnionDurationBaseline_p038d4b5e S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS UnionStatusPreg1 AS SELECT S.dim0 AS "Dim0", S.param_value AS "Value" FROM UnionStatusPreg1_pc4e9805e S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS T01_LifeExpectancy AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM T01_LifeExpectancy_vf4cddad0 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS T02_TotalPopulationByYear AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T02_TotalPopulationByYear_vf4f55780 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS T03_FertilityByAge AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T03_FertilityByAge_v5dc77583 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS T04_FertilityRatesByAgeGroup AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM T04_FertilityRatesByAgeGroup_v1f93417b S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS T05_CohortFertility AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM T05_CohortFertility_v284c576e S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS T06_BirthsByUnion AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T06_BirthsByUnion_v7bb3113c S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');
CREATE VIEW IF NOT EXISTS T07_FirstUnionFormation AS SELECT S.dim0 AS "Dim0", S.expr_id AS "Dim1", S.expr_value AS "Value" FROM T07_FirstUnionFormation_v02fc7f1d S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'd976aa2fb999f097468bb2ea098c4daf');

