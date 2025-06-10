--
-- compatibility views for model: OzProjGenX
-- model digest:   1da1caabb11915156f8825253fb7d62d
-- script created: 2025-06-01 18:50:24.518
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
CREATE VIEW IF NOT EXISTS ImmigrantAgeDist AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.param_value AS "Value" FROM ImmigrantAgeDist_p55f56410 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS IndigenousProportion AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.param_value AS "Value" FROM IndigenousProportion_p189bb858 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS MicroDataOutputFile AS SELECT S.param_value AS "Value" FROM MicroDataOutputFile_p6d28ab86 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS NativeBorn AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.param_value AS "Value" FROM NativeBorn_p81aeb1ac S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS RecentArrival AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.param_value AS "Value" FROM RecentArrival_p6140f8db S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS RegionAgeSexDistn AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.dim2 AS "Dim2", S.param_value AS "Value" FROM RegionAgeSexDistn_pc358a4fc S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS SimulationCases AS SELECT S.param_value AS "Value" FROM SimulationCases_p8b4bccb7 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS SimulationSeed AS SELECT S.param_value AS "Value" FROM SimulationSeed_p3df984c3 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS StartPopDistn AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.param_value AS "Value" FROM StartPopDistn_pcaf025fb S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS InitialIndigenous AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM InitialIndigenous_v64c27595 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS InitialNativeBorn AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM InitialNativeBorn_v78e403ca S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS InitialPopCounts AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM InitialPopCounts_vc107a6da S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS InitialRecentArrival AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM InitialRecentArrival_v25c09108 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS InitialRegion AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM InitialRegion_v77bfb15b S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');
CREATE VIEW IF NOT EXISTS InitialYearsSinceArrival AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.dim2 AS "Dim2", S.expr_id AS "Dim3", S.expr_value AS "Value" FROM InitialYearsSinceArrival_v44cd422f S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = '1da1caabb11915156f8825253fb7d62d');

