--
-- drop compatibility views for model: SM1
-- model digest:   db37c5704473ae83fea0a4e8d68a4804
-- script created: 2025-06-01 18:51:19.092
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
DROP VIEW AuditThreshold;
DROP VIEW EarningsNonZeroProportion;
DROP VIEW EarningsScaleFactor;
DROP VIEW EarningsSigma;
DROP VIEW GuaranteedAnnualIncome;
DROP VIEW HighIncomeThreshold;
DROP VIEW MortalityHazard;
DROP VIEW RegionDistribution;
DROP VIEW SE_EarningsNonZeroProportion;
DROP VIEW SE_EarningsScaleFactor;
DROP VIEW SE_EarningsSigma;
DROP VIEW SimulationCases;
DROP VIEW SimulationSeed;

--
-- drop output tables compatibility views
--
DROP VIEW ExampleTable;

