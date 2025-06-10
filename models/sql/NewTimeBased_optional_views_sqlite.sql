--
-- compatibility views for model: NewTimeBased
-- model digest:   49cec10414c928a253ff912362828de1
-- script created: 2025-06-01 18:49:08.290
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
CREATE VIEW IF NOT EXISTS MortalityHazard AS SELECT S.param_value AS "Value" FROM MortalityHazard_pf05190dd S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '49cec10414c928a253ff912362828de1');
CREATE VIEW IF NOT EXISTS SimulationEnd AS SELECT S.param_value AS "Value" FROM SimulationEnd_p65f25c39 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '49cec10414c928a253ff912362828de1');
CREATE VIEW IF NOT EXISTS SimulationSeed AS SELECT S.param_value AS "Value" FROM SimulationSeed_p3df984c3 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '49cec10414c928a253ff912362828de1');
CREATE VIEW IF NOT EXISTS StartingPopulationSize AS SELECT S.param_value AS "Value" FROM StartingPopulationSize_pc1e4bf5a S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '49cec10414c928a253ff912362828de1');

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS DurationOfLife AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM DurationOfLife_v52e65519 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '49cec10414c928a253ff912362828de1');

