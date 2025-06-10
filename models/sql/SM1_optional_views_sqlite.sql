--
-- compatibility views for model: SM1
-- model digest:   db37c5704473ae83fea0a4e8d68a4804
-- script created: 2025-06-01 18:51:19.092
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
CREATE VIEW IF NOT EXISTS AuditThreshold AS SELECT S.param_value AS "Value" FROM AuditThreshold_p564b4d28 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS EarningsNonZeroProportion AS SELECT S.param_value AS "Value" FROM EarningsNonZeroProportion_p14a04d8a S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS EarningsScaleFactor AS SELECT S.param_value AS "Value" FROM EarningsScaleFactor_p648c9f79 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS EarningsSigma AS SELECT S.param_value AS "Value" FROM EarningsSigma_pb7764537 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS GuaranteedAnnualIncome AS SELECT S.param_value AS "Value" FROM GuaranteedAnnualIncome_p35cf57f7 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS HighIncomeThreshold AS SELECT S.param_value AS "Value" FROM HighIncomeThreshold_p26d4f8f8 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS MortalityHazard AS SELECT S.param_value AS "Value" FROM MortalityHazard_pf05190dd S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS RegionDistribution AS SELECT S.dim0 AS "Dim0", S.param_value AS "Value" FROM RegionDistribution_p961ffc70 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS SE_EarningsNonZeroProportion AS SELECT S.param_value AS "Value" FROM SE_EarningsNonZeroProportion_p1265a70f S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS SE_EarningsScaleFactor AS SELECT S.param_value AS "Value" FROM SE_EarningsScaleFactor_pa7c55617 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS SE_EarningsSigma AS SELECT S.param_value AS "Value" FROM SE_EarningsSigma_pa08cbe10 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS SimulationCases AS SELECT S.param_value AS "Value" FROM SimulationCases_p8b4bccb7 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');
CREATE VIEW IF NOT EXISTS SimulationSeed AS SELECT S.param_value AS "Value" FROM SimulationSeed_p3df984c3 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS ExampleTable AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM ExampleTable_v8121c486 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'db37c5704473ae83fea0a4e8d68a4804');

