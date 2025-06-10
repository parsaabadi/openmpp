--
-- drop model tables: IDMM
-- model digest:      bd5730c6aec4fe70d3da6d8f3386d3c9
-- script created:    2025-06-01 18:49:43.149
--
-- DROP MODEL TABLES
-- DO NOT USE THIS SQL UNLESS YOU HAVE TO
-- IT WILL DELETE ALL MODEL DATA
--

--
-- drop model output views and tables
--
DROP VIEW X01_History_dae891476;
DROP TABLE X01_History_aae891476;
DROP TABLE X01_History_vae891476;
DROP VIEW X02_Host_Events_d32406d68;
DROP TABLE X02_Host_Events_a32406d68;
DROP TABLE X02_Host_Events_v32406d68;
DROP VIEW X03_Ticker_Events_d5cc6f126;
DROP TABLE X03_Ticker_Events_a5cc6f126;
DROP TABLE X03_Ticker_Events_v5cc6f126;

--
-- drop model input parameters tables
--
DROP TABLE ContactsOutPerHost_p99866eac;
DROP TABLE ContactsOutPerHost_w99866eac;
DROP TABLE ContagiousPhaseDuration_p32e12465;
DROP TABLE ContagiousPhaseDuration_w32e12465;
DROP TABLE DumpSickContactProbability_p574f1194;
DROP TABLE DumpSickContactProbability_w574f1194;
DROP TABLE EnableChangeContactsEvent_pc1ee5c24;
DROP TABLE EnableChangeContactsEvent_wc1ee5c24;
DROP TABLE ImmunePhaseDuration_pfb350298;
DROP TABLE ImmunePhaseDuration_wfb350298;
DROP TABLE InitialDiseasePrevalence_p8385b5f0;
DROP TABLE InitialDiseasePrevalence_w8385b5f0;
DROP TABLE LatentPhaseDuration_p6466af56;
DROP TABLE LatentPhaseDuration_w6466af56;
DROP TABLE MeanChangeContactsInterval_paeffaeba;
DROP TABLE MeanChangeContactsInterval_waeffaeba;
DROP TABLE MeanContactInterval_p53eef4a7;
DROP TABLE MeanContactInterval_w53eef4a7;
DROP TABLE NumberOfHosts_p5ba164d1;
DROP TABLE NumberOfHosts_w5ba164d1;
DROP TABLE SimulationEnd_p65f25c39;
DROP TABLE SimulationEnd_w65f25c39;
DROP TABLE SimulationSeed_p3df984c3;
DROP TABLE SimulationSeed_w3df984c3;
DROP TABLE TransmissionEfficiency_p25423a19;
DROP TABLE TransmissionEfficiency_w25423a19;

