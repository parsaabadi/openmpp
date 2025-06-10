--
-- compatibility views for model: NewCaseBased
-- model digest:   be31709dbf963f5328800ece46e4954f
-- script created: 2025-06-01 18:48:51.106
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
CREATE VIEW IF NOT EXISTS MortalityHazard AS SELECT S.param_value AS "Value" FROM MortalityHazard_pf05190dd S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'be31709dbf963f5328800ece46e4954f');
CREATE VIEW IF NOT EXISTS SimulationCases AS SELECT S.param_value AS "Value" FROM SimulationCases_p8b4bccb7 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'be31709dbf963f5328800ece46e4954f');
CREATE VIEW IF NOT EXISTS SimulationSeed AS SELECT S.param_value AS "Value" FROM SimulationSeed_p3df984c3 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'be31709dbf963f5328800ece46e4954f');

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS DurationOfLife AS SELECT S.expr_id AS "Dim0", S.expr_value AS "Value" FROM DurationOfLife_vd7fa6899 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'be31709dbf963f5328800ece46e4954f');

