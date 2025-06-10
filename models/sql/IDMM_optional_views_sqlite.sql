--
-- compatibility views for model: IDMM
-- model digest:   bd5730c6aec4fe70d3da6d8f3386d3c9
-- script created: 2025-06-01 18:49:43.149
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
CREATE VIEW IF NOT EXISTS ContactsOutPerHost AS SELECT S.param_value AS "Value" FROM ContactsOutPerHost_p99866eac S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS ContagiousPhaseDuration AS SELECT S.param_value AS "Value" FROM ContagiousPhaseDuration_p32e12465 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS DumpSickContactProbability AS SELECT S.param_value AS "Value" FROM DumpSickContactProbability_p574f1194 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS EnableChangeContactsEvent AS SELECT S.param_value AS "Value" FROM EnableChangeContactsEvent_pc1ee5c24 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS ImmunePhaseDuration AS SELECT S.param_value AS "Value" FROM ImmunePhaseDuration_pfb350298 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS InitialDiseasePrevalence AS SELECT S.param_value AS "Value" FROM InitialDiseasePrevalence_p8385b5f0 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS LatentPhaseDuration AS SELECT S.param_value AS "Value" FROM LatentPhaseDuration_p6466af56 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS MeanChangeContactsInterval AS SELECT S.param_value AS "Value" FROM MeanChangeContactsInterval_paeffaeba S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS MeanContactInterval AS SELECT S.param_value AS "Value" FROM MeanContactInterval_p53eef4a7 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS NumberOfHosts AS SELECT S.param_value AS "Value" FROM NumberOfHosts_p5ba164d1 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS SimulationEnd AS SELECT S.param_value AS "Value" FROM SimulationEnd_p65f25c39 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS SimulationSeed AS SELECT S.param_value AS "Value" FROM SimulationSeed_p3df984c3 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS TransmissionEfficiency AS SELECT S.param_value AS "Value" FROM TransmissionEfficiency_p25423a19 S WHERE S.sub_id = 0 AND S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');

--
-- output tables compatibility views
--
CREATE VIEW IF NOT EXISTS X01_History AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM X01_History_vae891476 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS X02_Host_Events AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM X02_Host_Events_v32406d68 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');
CREATE VIEW IF NOT EXISTS X03_Ticker_Events AS SELECT S.dim0 AS "Dim0", S.dim1 AS "Dim1", S.expr_id AS "Dim2", S.expr_value AS "Value" FROM X03_Ticker_Events_v5cc6f126 S WHERE S.run_id = ( SELECT MIN(RL.run_id) FROM run_lst RL INNER JOIN model_dic M ON (M.model_id = RL.model_id) WHERE M.model_digest = 'bd5730c6aec4fe70d3da6d8f3386d3c9');

