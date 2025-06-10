--
-- drop compatibility views for model: IDMM
-- model digest:   bd5730c6aec4fe70d3da6d8f3386d3c9
-- script created: 2025-06-01 18:49:43.149
--
-- Dear user:
--   this part of database is optional and NOT used by openM++
--   if you want it for any reason please enjoy else just ignore it
-- Or other words:
--   if you don't know what is this then you don't need it
--

--
-- drop input parameters compatibility views
--
DROP VIEW ContactsOutPerHost;
DROP VIEW ContagiousPhaseDuration;
DROP VIEW DumpSickContactProbability;
DROP VIEW EnableChangeContactsEvent;
DROP VIEW ImmunePhaseDuration;
DROP VIEW InitialDiseasePrevalence;
DROP VIEW LatentPhaseDuration;
DROP VIEW MeanChangeContactsInterval;
DROP VIEW MeanContactInterval;
DROP VIEW NumberOfHosts;
DROP VIEW SimulationEnd;
DROP VIEW SimulationSeed;
DROP VIEW TransmissionEfficiency;

--
-- drop output tables compatibility views
--
DROP VIEW X01_History;
DROP VIEW X02_Host_Events;
DROP VIEW X03_Ticker_Events;

