--
-- create model tables: IDMM
-- model digest:        bd5730c6aec4fe70d3da6d8f3386d3c9
-- script created:      2025-06-01 18:49:43.149
--

--
-- create model input parameters
--
CREATE TABLE IF NOT EXISTS ContactsOutPerHost_p99866eac (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value INT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS ContactsOutPerHost_w99866eac (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value INT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS ContagiousPhaseDuration_p32e12465 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS ContagiousPhaseDuration_w32e12465 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS DumpSickContactProbability_p574f1194 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS DumpSickContactProbability_w574f1194 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS EnableChangeContactsEvent_pc1ee5c24 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value SMALLINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS EnableChangeContactsEvent_wc1ee5c24 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value SMALLINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS ImmunePhaseDuration_pfb350298 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS ImmunePhaseDuration_wfb350298 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS InitialDiseasePrevalence_p8385b5f0 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS InitialDiseasePrevalence_w8385b5f0 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS LatentPhaseDuration_p6466af56 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS LatentPhaseDuration_w6466af56 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS MeanChangeContactsInterval_paeffaeba (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS MeanChangeContactsInterval_waeffaeba (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS MeanContactInterval_p53eef4a7 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS MeanContactInterval_w53eef4a7 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS NumberOfHosts_p5ba164d1 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value INT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS NumberOfHosts_w5ba164d1 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value INT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationEnd_p65f25c39 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationEnd_w65f25c39 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_p3df984c3 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS SimulationSeed_w3df984c3 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value BIGINT NOT NULL, PRIMARY KEY (set_id, sub_id));
CREATE TABLE IF NOT EXISTS TransmissionEfficiency_p25423a19 (run_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (run_id, sub_id));
CREATE TABLE IF NOT EXISTS TransmissionEfficiency_w25423a19 (set_id INT NOT NULL, sub_id SMALLINT NOT NULL, param_value FLOAT NOT NULL, PRIMARY KEY (set_id, sub_id));

--
-- create model output tables and views
--
CREATE TABLE IF NOT EXISTS X01_History_aae891476 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS X01_History_vae891476 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS X01_History_dae891476 AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM X01_History_aae891476 A WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS X02_Host_Events_a32406d68 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS X02_Host_Events_v32406d68 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS X02_Host_Events_d32406d68 AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM X02_Host_Events_a32406d68 A WHERE A.acc_id = 0;
CREATE TABLE IF NOT EXISTS X03_Ticker_Events_a5cc6f126 (run_id INT NOT NULL, acc_id SMALLINT NULL, sub_id SMALLINT NOT NULL, dim0 INT NOT NULL, dim1 INT NOT NULL, acc_value FLOAT NULL, PRIMARY KEY (run_id, acc_id, sub_id, dim0, dim1));
CREATE TABLE IF NOT EXISTS X03_Ticker_Events_v5cc6f126 (run_id INT NOT NULL, expr_id SMALLINT NULL,dim0 INT NOT NULL, dim1 INT NOT NULL,  expr_value FLOAT NULL, PRIMARY KEY (run_id, expr_id, dim0, dim1));
CREATE VIEW IF NOT EXISTS X03_Ticker_Events_d5cc6f126 AS  SELECT A.run_id, A.sub_id, A.dim0 AS "Dim0", A.dim1 AS "Dim1", A.acc_value AS "acc0", ( A.acc_value ) AS "Expr0" FROM X03_Ticker_Events_a5cc6f126 A WHERE A.acc_id = 0;

