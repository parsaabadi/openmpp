/**
 * @file om_developer.cpp
 * Developer-supplied C++ code
 */

#include "omc/omPch.h"
#include "omc/omSimulation.h"
using namespace openm;

#line 1 "./AttributeGroups.ompp"
/* NOTE(AttributeGroups, EN)
	This module contains declarations of attribute groups for testing.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

//EN All tables in Tables.mpp




//EN All Fertility parameters

















//EN Union-related attributes









//EN Union-related attributes




//EN Commonly-used attributes







#endif // Hide non-C++ syntactic island from IDE

#line 1 "./ExplicitNames.ompp"


/*
//NAME T02_TotalPopulationByYear.Dim0 age
//NAME T02_TotalPopulationByYear.Expr0 pop
//NAME T02_TotalPopulationByYear.Expr1 py

//NAME UnionDurationBaseline.Dim0 dimensionfirst
//NAME UnionDurationBaseline.Dim1 order1
*/
#line 1 "./ExtraTests.mpp"
//options event_trace = on;
//options case_checksum = on;

#line 1 "./Fertility.mpp"
///////////////////////////////////////////////////////////////////////////
// Fertility.mpp                                                         //
///////////////////////////////////////////////////////////////////////////

/* NOTE(Fertility, EN)
	This module simulates first pregnancy events.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Parameter definitions



//EN Age baseline for first pregnancy 		


//EN Relative risks of union status on first pregnancy



//EN Fertility  




///////////////////////////////////////////////////////////////////////////
// Actor states and event definitions

//EN Parity status

//EN Childless
//EN Pregnant




//EN Parity status derived from the state parity



//EN First pregnancy event 

  

#endif // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Event implementation

/*NOTE(Person.FirstPregEvent, EN)
	The first pregnancy event. This is the main event of analysis and
	censures all future union events.
*/

TIME Person::timeFirstPregEvent()						
{
	double dHazard = 0;
	TIME event_time = TIME_INFINITE;
	if (parity_status == PS_CHILDLESS)  			
	{														
		dHazard = AgeBaselinePreg1[age_status]
		  * UnionStatusPreg1[union_status];
	    if (dHazard > 0)
	    {											
			event_time = WAIT(-log(RandUniform(1)) / dHazard);
		}
  }
  return event_time;								
}

void Person::FirstPregEvent()						
{													
	parity_status = PS_PREGNANT;										 	
} 






#line 1 "./GeneratedNames.ompp"

// Classification LIFECYCLE_Person: Lifecycle
//NAME LC_Person_enter_simulation enter_simulation
//NAME LC_Person_exit_simulation_external exit_simulation_external
//NAME LC_Person_DeathEvent DeathEvent
//NAME LC_Person_FirstPregEvent FirstPregEvent
//NAME LC_Person_Union1DissolutionEvent Union1DissolutionEvent
//NAME LC_Person_Union1FormationEvent Union1FormationEvent
//NAME LC_Person_Union2DissolutionEvent Union2DissolutionEvent
//NAME LC_Person_Union2FormationEvent Union2FormationEvent
//NAME LC_Person_UnionPeriod2Event UnionPeriod2Event

// Classification LIFE_STATE: Life status
//NAME LS_ALIVE Alive
//NAME LS_NOT_ALIVE Dead

// Classification PARITY_STATE: Parity status
//NAME PS_CHILDLESS Childless
//NAME PS_PREGNANT Pregnant

// Classification UNION_ORDER: Union order
//NAME UO_FIRST First_union
//NAME UO_SECOND Second_union

// Classification UNION_STATE: Union status
//NAME US_NEVER_IN_UNION Never_in_union
//NAME US_FIRST_UNION_PERIOD1 First_union_3_years
//NAME US_FIRST_UNION_PERIOD2 First_Union_3_years
//NAME US_AFTER_FIRST_UNION After_first_union
//NAME US_SECOND_UNION Second_union
//NAME US_AFTER_SECOND_UNION After_second_union

// Parameter AgeBaselineForm1: Age baseline for first union formation
//NAME AgeBaselineForm1.Dim0 X_2_5_year_age_intervals

// Parameter AgeBaselinePreg1: Age baseline for first pregnancy
//NAME AgeBaselinePreg1.Dim0 X_2_5_year_age_intervals

// Parameter ProbMort: Death probabilities
//NAME ProbMort.Dim0 Simulated_age_range

// Parameter SeparationDurationBaseline: Separation Duration Baseline of 2nd Formation
//NAME SeparationDurationBaseline.Dim0 Duration_since_union_dissolution

// Parameter UnionDurationBaseline: Union Duration Baseline of Dissolution
//NAME UnionDurationBaseline.Dim0 Union_order
//NAME UnionDurationBaseline.Dim1 Duration_of_current_union

// Parameter UnionStatusPreg1: Relative risks of union status on first pregnancy
//NAME UnionStatusPreg1.Dim0 Union_status

// Table T01_LifeExpectancy: Life Expectancy
//NAME T01_LifeExpectancy.Expr0 Total_simulated_cases
//NAME T01_LifeExpectancy.Expr1 Total_duration
//NAME T01_LifeExpectancy.Expr2 Life_expectancy

// Table T02_TotalPopulationByYear: Life table
//NAME T02_TotalPopulationByYear.Dim0 Age
//NAME T02_TotalPopulationByYear.Expr0 Population_start_of_year
//NAME T02_TotalPopulationByYear.Expr1 Average_population_in_year

// Table T03_FertilityByAge: Age-specific fertility
//NAME T03_FertilityByAge.Dim0 Age
//NAME T03_FertilityByAge.Expr0 First_birth_rate_all_women
//NAME T03_FertilityByAge.Expr1 First_birth_rate_woman_at_risk

// Table T04_FertilityRatesByAgeGroup: Fertility rates by age group
//NAME T04_FertilityRatesByAgeGroup.Dim0 Age_interval
//NAME T04_FertilityRatesByAgeGroup.Dim1 Union_Status
//NAME T04_FertilityRatesByAgeGroup.Expr0 Fertility

// Table T05_CohortFertility: Cohort fertility
//NAME T05_CohortFertility.Expr0 Av_age_at_1st_pregnancy
//NAME T05_CohortFertility.Expr1 Childlessness
//NAME T05_CohortFertility.Expr2 Percent_one_child

// Table T06_BirthsByUnion: Pregnancies by union status & order
//NAME T06_BirthsByUnion.Dim0 Union_Status_at_pregnancy
//NAME T06_BirthsByUnion.Expr0 Number_of_pregnancies

// Table T07_FirstUnionFormation: First union formation
//NAME T07_FirstUnionFormation.Dim0 Age_group
//NAME T07_FirstUnionFormation.Expr0 First_union_formation_risk

#line 1 "./Mortality.mpp"
///////////////////////////////////////////////////////////////////////////
// Mortality.mpp                                                         //
///////////////////////////////////////////////////////////////////////////

/* NOTE(Mortality, EN)
	This module simulates the death event. Mortality can be switched off
	by the user in which case all actors reach the maximum age. This
	is useful in fertility analysis as e.g. TFR is calculated assuming
	survival over the whole fertile period.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Parameter definitions

///////////////////////////////////////////////////////////////////////////
// Actor states and event definitions


//EN Switch mortality on/off
//EN Death probabilities  


//EN Mortality




///////////////////////////////////////////////////////////////////////////
// Actor states and event definitions

//EN Life status

//EN Alive 
//EN Dead




//EN Life Status
//EN Death Event 
  

#endif // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Events implementation

/*NOTE(Person.DeathEvent, EN)
	The death event. Death occurs either according to a life table or - if
	the parameter CanDie is set false, at the maximum possible age.
*/

TIME Person::timeDeathEvent()				
{
	TIME event_time = TIME_INFINITE;
	if (CanDie)										
	{
		if (ProbMort[integer_age] >= 1) 			
		{
	  		event_time = WAIT(0);
		}
		else 								
		{
			event_time = WAIT(-log(RandUniform(3)) / 
				              -log(1 - ProbMort[integer_age]));
		}
	}
	// Death event can not occur after the maximum duration of life
	if (event_time > MAX(LIFE)) 						
	{
		event_time = MAX(LIFE);
	}
	return event_time;
}
	  
void Person::DeathEvent()					
{
	life_status = LS_NOT_ALIVE; 
	Finish();
}



#line 1 "./PersonCore.mpp"
///////////////////////////////////////////////////////////////////////////
// PersonCore.mpp                                                        //
///////////////////////////////////////////////////////////////////////////

/* NOTE(PersonCore, EN)
	This module contains basic functions and actor states not specific
	to the individual behaviours organized in separate modules.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Type definitions 

//EN Simulated age range




//EN 2.5 year age intervals




//EN Union status

//EN Never in union	
//EN First union < 3 years
//EN First Union > 3 years
//EN After first union	
//EN Second union
//EN After second union


///////////////////////////////////////////////////////////////////////////
// Actor states and functions

//EN Individual

//EN Current integer age


//EN Current age interval


//EN Function starting the life of an actor


//EN Function finishing the life of an actor

  

#endif // Hide non-C++ syntactic island from IDE

/*NOTE(Person.Start, EN)
	The Start function initializes actor variables before simulation
	of the actor commences.
*/
void Person::Start()
{
    // Initialize all attributes (OpenM++).
    initialize_attributes();

	// Age and time are variables automatically maintained by 
	// Modgen. They can be set only in the Start function
	age = 0;		 
	time = 0;

    // Have the entity enter the simulation (OpenM++).
    enter_simulation();
}

/*NOTE(Person.Finish, EN)
	The Finish function terminates the simulation of an actor.
*/
void Person::Finish()
{
    // Have the entity exit the simulation (OpenM++).
    exit_simulation();

	// After the code in this function (if any) is executed,
	// Modgen removes the actor from tables and from the simulation.
	// Modgen also recuperates any memory used by the actor.
}
#line 1 "./RiskPaths.mpp"
///////////////////////////////////////////////////////////////////////////
// Main simulation engine: RiskPaths.mpp	DO NOT CHANGE THIS FILE      //
///////////////////////////////////////////////////////////////////////////

/* NOTE(RiskPaths, EN)
	This module carrying the same name as the model (RiskPaths)	contains 
	some basic model settings and the model's simulation engine. When 
	creating a new model, such a file is automatically created by the
	Modgen model wizard. Usually no changes are necessary in its code.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Model settings

							// Model version
					// Model type
						// Continuous time model

// Language options

// English						
// Français


#endif // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Simulation Engine


/**
 * Simulates a single case.
 * 
 * Called by code in a simulation framework module.
 */
void CaseSimulation(case_info &ci)
{
    extern void SimulateEvents(); // defined in a simulation framework module

	// Initialize the person actor
	auto prPerson = new Person();
	prPerson->Start();

	// Simulate events until there are no more.
    SimulateEvents();
}

/**
 * Invoked at the beginning of the Simulation function.
 *
 * @param [in,out] ci Additional information related to the case.
 */
void Simulation_start(case_info &ci)
{
#if !defined(MODGEN)
	theLog->logMsg(LT("Welcome to the RiskPaths model!"));
#endif
	// Initialize case information in ci (if used).
}

/**
 * Invoked at the end of the Simulation function.
 *
 * @param [in,out] ci Additional information related to the case.
 */
void Simulation_end(case_info &ci)
{
    // Finalize case information in ci (if used).
}

#line 1 "./RiskPathsEN_LBL.mpp"
// English

// (just Modgen-generated labels / Étiquettes générées par Modgen seulement)



//==============================/
//                              /
// classification               /
//                              /
//==============================/



//==============================/
//                              /
// range                        /
//                              /
//==============================/



//==============================/
//                              /
// partition                    /
//                              /
//==============================/



//==============================/
//                              /
// parameter group              /
//                              /
//==============================/



//==============================/
//                              /
// parameter                    /
//                              /
//==============================/



//==============================/
//                              /
// actor                        /
//                              /
//==============================/



//==============================/
// actor Person                 /
//==============================/




     //==============================/
     // event                        /
     //==============================/


     //LABEL ( Person.FirstPregEvent, EN ) FirstPregEvent
     //LABEL ( Person.Union1DissolutionEvent, EN ) Union1DissolutionEvent
     //LABEL ( Person.Union1FormationEvent, EN ) Union1FormationEvent
     //LABEL ( Person.Union2DissolutionEvent, EN ) Union2DissolutionEvent
     //LABEL ( Person.Union2FormationEvent, EN ) Union2FormationEvent
     //LABEL ( Person.UnionPeriod2Event, EN ) UnionPeriod2Event


//==============================/
//                              /
// table group                  /
//                              /
//==============================/



//==============================/
//                              /
// table                        /
//                              /
//==============================/



//==============================/
// table T01_LifeExpectancy     /
//==============================/


     //LABEL ( T01_LifeExpectancy.Dim0, EN ) Selected Quantities




//=================================/
// table T02_TotalPopulationByYear /
//=================================/


     //LABEL ( T02_TotalPopulationByYear.Dim1, EN ) Selected Quantities




//==============================/
// table T03_FertilityByAge     /
//==============================/


     //LABEL ( T03_FertilityByAge.Dim1, EN ) Selected Quantities




//====================================/
// table T04_FertilityRatesByAgeGroup /
//====================================/


     //LABEL ( T04_FertilityRatesByAgeGroup.Dim0, EN ) Fertility




//==============================/
// table T05_CohortFertility    /
//==============================/


     //LABEL ( T05_CohortFertility.Dim0, EN ) Selected Quantities




//==============================/
// table T06_BirthsByUnion      /
//==============================/


     //LABEL ( T06_BirthsByUnion.Dim0, EN ) Number of pregnancies




//===============================/
// table T07_FirstUnionFormation /
//===============================/


     //LABEL ( T07_FirstUnionFormation.Dim1, EN ) First union formation risk




//==============================/
//                              /
// user table                   /
//                              /
//==============================/



//==============================/
//                              /
// module                       /
//                              /
//==============================/


#line 1 "./RiskPathsFR.mpp"
//LABEL ( RiskPathsFR, EN ) 



//==============================/
//                              /
// classification               /
//                              /
//==============================/



//==============================/
// classification LIFE_STATE    /
//==============================/


//LABEL ( LIFE_STATE, FR ) État vital

     //LABEL ( LS_ALIVE, FR ) En vie
     //LABEL ( LS_NOT_ALIVE, FR ) Décédé(e)


//==============================/
// classification PARITY_STATE  /
//==============================/


//LABEL ( PARITY_STATE, FR ) État de parité

     //LABEL ( PS_CHILDLESS, FR ) Sans enfants
     //LABEL ( PS_PREGNANT, FR ) Enceinte


//==============================/
// classification UNION_ORDER   /
//==============================/


//LABEL ( UNION_ORDER, FR ) Ordre des unions

     //LABEL ( UO_FIRST, FR ) Première union
     //LABEL ( UO_SECOND, FR ) Deuxième union


//==============================/
// classification UNION_STATE   /
//==============================/


//LABEL ( UNION_STATE, FR ) Situation dunion

     //LABEL ( US_NEVER_IN_UNION, FR ) Jamais dans une union
     //LABEL ( US_FIRST_UNION_PERIOD1, FR ) Première union << 3 années
     //LABEL ( US_FIRST_UNION_PERIOD2, FR ) Première union >> 3 années
     //LABEL ( US_AFTER_FIRST_UNION, FR ) Après la première union
     //LABEL ( US_SECOND_UNION, FR ) Deuxième union
     //LABEL ( US_AFTER_SECOND_UNION, FR ) Après la deuxième union


//==============================/
//                              /
// range                        /
//                              /
//==============================/

//LABEL ( LIFE, FR ) Tranche dâge simulée


//==============================/
//                              /
// partition                    /
//                              /
//==============================/

//LABEL ( AGE_FERTILEYEARS, FR ) Partition de la tranche dâge de fécondité
//LABEL ( AGEINT_STATE, FR ) Intervalles dâge de 2,5 ans
//LABEL ( DISSOLUTION_DURATION, FR ) Temps écoulé depuis la dissolution de lunion
//LABEL ( UNION_DURATION, FR ) Durée de lunion courante


//==============================/
//                              /
// parameter group              /
//                              /
//==============================/

//LABEL ( P01_Mortality, FR ) Mortalité
//LABEL ( P02_Ferility, FR ) Fécondité
//LABEL ( P03_Unions, FR ) Paramètres dunion


//==============================/
//                              /
// parameter                    /
//                              /
//==============================/

//LABEL ( AgeBaselineForm1, FR ) Âge de référence pour la formation de la première union
//LABEL ( AgeBaselinePreg1, FR ) Âge de référence pour la première grossesse
//LABEL ( CanDie, FR ) Activation/désactivation de la mortalité
//LABEL ( ProbMort, FR ) Probabilités de décès
//LABEL ( SeparationDurationBaseline, FR ) Durée de référence de la séparation pour la deuxième formation dune union
//LABEL ( UnionDurationBaseline, FR ) Durée de référence de lunion pour la dissolution
//LABEL ( UnionStatusPreg1, FR ) Risques relatifs de la situation dunion à la première grossesse


//==============================/
//                              /
// actor                        /
//                              /
//==============================/



//==============================/
// actor Person                 /
//==============================/


//LABEL ( Person, FR ) Individu



     //==============================/
     // state                        /
     //==============================/


     //LABEL ( Person.age_status, FR ) Intervalle dâge courant
     //LABEL ( Person.dissolution_duration, FR ) Intervalle de temps depuis la dissolution de lunion
     //LABEL ( Person.dissolution_hazard, FR ) Risque de dissolution de lunion
     //LABEL ( Person.formation_hazard, FR ) Risque de formation dune union
     //LABEL ( Person.in_union, FR ) Dans une union à lheure actuelle
     //LABEL ( Person.integer_age, FR ) Âge courant en nombre entier
     //LABEL ( Person.life_status, FR ) Situation vitale
     //LABEL ( Person.parity_status, FR ) Situation de parité déterminée daprès létat de parité
     //LABEL ( Person.preg_hazard, FR ) Risque de grossesse
     //LABEL ( Person.union_duration, FR ) Intervalle de temps depuis la formation de lunion
     //LABEL ( Person.union_period2_change, FR ) Moment du changement de période dunion
     //LABEL ( Person.union_status, FR ) Situation dunion
     //LABEL ( Person.unions, FR ) Compteur dunions


     //==============================/
     // event                        /
     //==============================/


     //LABEL ( Person.DeathEvent, FR ) Événement de décès

/* NOTE ( Person.DeathEvent, FR )	Lévénement de décès. Le décès survient conformément à une table de 
mortalité ou, si la valeur du paramètre CanDie (peut mourir) est Faux, à lâge maximal possible. 
*/

     //LABEL ( Person.FirstPregEvent, FR ) Événement de première grossesse

/* NOTE ( Person.FirstPregEvent, FR )	Le premier événement de grossesse. Il sagit de lévénement 
principal de lanalyse et il censure tous les futurs événements dunion. 
*/

     //LABEL ( Person.Union1DissolutionEvent, FR ) Événement de dissolution de lunion 1

/* NOTE ( Person.Union1DissolutionEvent, FR )	Le premier évènement de dissolution dunion. 
Les événements dunion ne sont simulés que pour les femmes sans enfants, car la grossesse 
censure la trajectoire des unions.
*/

     //LABEL ( Person.Union1FormationEvent, FR ) Événement de formation de lunion 1

/* NOTE ( Person.Union1FormationEvent, FR )	Le premier évènement de formation dunion. 
Les événements dunion ne sont simulés que pour les femmes sans enfants, car la grossesse censure 
la trajectoire des unions.
*/

     //LABEL ( Person.Union2DissolutionEvent, FR ) Événement de dissolution de lunion 2

/* NOTE ( Person.Union2DissolutionEvent, FR )	Le deuxième évènement de dissolution dunion. 
Les événements dunion ne sont simulés que pour les femmes sans enfants, car la grossesse 
censure la trajectoire des unions.
*/

     //LABEL ( Person.Union2FormationEvent, FR ) Événement de formation de lunion 2

/* NOTE ( Person.Union2FormationEvent, FR )	Le deuxième évènement de formation dunion. 
Les événements dunion ne sont simulés que pour les femmes sans enfants, car la grossesse 
censure la trajectoire des unions.
*/

     //LABEL ( Person.UnionPeriod2Event, FR ) Événement de période dunion 2

/* NOTE ( Person.UnionPeriod2Event, FR )	Événement horloge qui modifie létat de durée 
de lunion union_status de US_FIRST_UNION_PERIOD1 à US_FIRST_UNION_PERIOD2. Cet évènement 
survient après trois années dans la première union. Lhorloge est réglée à formation de 
la première union. 
*/



     //==============================/
     // function                     /
     //==============================/


     //LABEL ( Person.Finish, FR ) Fonction mettant fin à la vie dun acteur

/* NOTE ( Person.Finish, FR )	La fonction Finish termine la simulation dun acteur. 
*/

     //LABEL ( Person.Start, FR ) Fonction faisant commencer la vie dun acteur

/* NOTE ( Person.Start, FR )	La fonction Start initialise les variables dun acteur 
avant que la simulation de cet acteur commence. 
*/



//==============================/
//                              /
// table group                  /
//                              /
//==============================/

//LABEL ( TG01_Life_Tables, FR ) Tables de mortalité
//LABEL ( TG02_Birth_Tables, FR ) Fécondité
//LABEL ( TG03_Union_Tables, FR ) Unions


//==============================/
//                              /
// table                        /
//                              /
//==============================/



//==============================/
// table T01_LifeExpectancy     /
//==============================/


//LABEL ( T01_LifeExpectancy, FR ) Espérance de vie

     //LABEL ( T01_LifeExpectancy.Dim0, FR ) Quantités choisies


     //LABEL ( T01_LifeExpectancy.Expr0, FR ) Nombre total de cas simulés
     //LABEL ( T01_LifeExpectancy.Expr1, FR ) Durée totale
     //LABEL ( T01_LifeExpectancy.Expr2, FR ) Espérance de vie


//=================================/
// table T02_TotalPopulationByYear /
//=================================/


//LABEL ( T02_TotalPopulationByYear, FR ) Table de mortalité

     //LABEL ( T02_TotalPopulationByYear.Dim1, FR ) Quantités choisies

     //LABEL ( T02_TotalPopulationByYear.Dim0, FR ) Âge

     //LABEL ( T02_TotalPopulationByYear.Expr0, FR ) Population au début de lannée
     //LABEL ( T02_TotalPopulationByYear.Expr1, FR ) Population moyenne durant lannée


//==============================/
// table T03_FertilityByAge     /
//==============================/


//LABEL ( T03_FertilityByAge, FR ) Fécondité par âge

     //LABEL ( T03_FertilityByAge.Dim1, FR ) Quantités choisies

     //LABEL ( T03_FertilityByAge.Dim0, FR ) Âge

     //LABEL ( T03_FertilityByAge.Expr0, FR ) Taux de première naissance pour toutes les femmes
     //LABEL ( T03_FertilityByAge.Expr1, FR ) Taux de première naissance pour les femmes à risque


//====================================/
// table T04_FertilityRatesByAgeGroup /
//====================================/


//LABEL ( T04_FertilityRatesByAgeGroup, FR ) Taux de fécondité par groupe dâge

     //LABEL ( T04_FertilityRatesByAgeGroup.Dim0, FR ) Fécondité

     //LABEL ( T04_FertilityRatesByAgeGroup.Dim1, FR ) Intervalle dâge
     //LABEL ( T04_FertilityRatesByAgeGroup.Dim2, FR ) Situation dunion

     //LABEL ( T04_FertilityRatesByAgeGroup.Expr0, FR ) Fécondité


//==============================/
// table T05_CohortFertility    /
//==============================/


//LABEL ( T05_CohortFertility, FR ) Fécondité de la cohorte

     //LABEL ( T05_CohortFertility.Dim0, FR ) Quantités choisies


     //LABEL ( T05_CohortFertility.Expr0, FR ) Âge moyen à la première grossesse
     //LABEL ( T05_CohortFertility.Expr1, FR ) Sans enfants
     //LABEL ( T05_CohortFertility.Expr2, FR ) Pourcentage ayant un enfant


//==============================/
// table T06_BirthsByUnion      /
//==============================/


//LABEL ( T06_BirthsByUnion, FR ) Grossesses selon la situation dunion et lordre de lunion

     //LABEL ( T06_BirthsByUnion.Dim0, FR ) Nombre de grossesses

     //LABEL ( T06_BirthsByUnion.Dim1, FR ) Situation dunion au moment de la grossesse

     //LABEL ( T06_BirthsByUnion.Expr0, FR ) Nombre de grossesses


//===============================/
// table T07_FirstUnionFormation /
//===============================/


//LABEL ( T07_FirstUnionFormation, FR ) Formation de la première union

     //LABEL ( T07_FirstUnionFormation.Dim1, FR ) Risque de formation de la première union

     //LABEL ( T07_FirstUnionFormation.Dim0, FR ) Groupe dâge

     //LABEL ( T07_FirstUnionFormation.Expr0, FR ) Risque de formation de la première union


//==============================/
//                              /
// user table                   /
//                              /
//==============================/



//==============================/
//                              /
// module                       /
//                              /
//==============================/

//LABEL ( Fertility, FR ) 

/* NOTE ( Fertility, FR )	Ce module stimule les événements de première grossesse. 
*/

//LABEL ( Mortality, FR ) 

/* NOTE ( Mortality, FR )	Ce module simule lévénement de décès. La mortalité peut être 
désactivée par lutilisateur, auquel cas les acteurs atteignent lâge maximal. Cette fonction 
est utile dans lanalyse de la fécondité, car par exemple, lindice synthétique de fécondité 
est calculé en supposant la survie pendant toute la période de fécondité.
*/

//LABEL ( PersonCore, FR ) 

/* NOTE ( PersonCore, FR )	Ce module contient les fonctions de base et les états dacteur non 
spécifiques aux comportements individuels classés dans des modules distincts.
*/

//LABEL ( RiskPaths, FR ) 

/* NOTE ( RiskPaths, FR )	Ce module portant le même nom que le modèle (RiskPaths) contient certains 
paramètres de modélisation de base et le moteur de simulation du modèle. 
Lors de la création dun nouveau modèle, ce fichier est créé automatiquement par le guide intelligent 
du modèle Modgen. Habituellement, aucun changement ne doit être apporté à son code.
*/

//LABEL ( RiskPathsFR, FR ) 
//LABEL ( Tables, FR ) 

/* NOTE ( Tables, FR )	Ce module contient toutes les définitions de tableau de RiskPaths.
*/

//LABEL ( Tracking, FR ) 

/* NOTE ( Tracking, FR )	Ce module définit les états pour le dépistage au moyen du BioBrowser. 
Les taux de risque calculés dans ce module sont des états dérivés qui sont utilisés uniquement 
pour les besoins du dépistage. 
*/

//LABEL ( Unions, FR ) 

/* NOTE ( Unions, FR )	Ce module simule les première et deuxième formations dunion et les 
première et deuxième dissolutions dunion.
*/


#line 1 "./RiskPathsFR_NOTR.mpp"
// Français

// (just authored text that is not translated / texte composé par concepteur jamais traduit seulement)



//==============================/
//                              /
// classification               /
//                              /
//==============================/



//==============================/
//                              /
// range                        /
//                              /
//==============================/



//==============================/
//                              /
// partition                    /
//                              /
//==============================/



//==============================/
//                              /
// parameter group              /
//                              /
//==============================/



//==============================/
//                              /
// parameter                    /
//                              /
//==============================/



//==============================/
//                              /
// actor                        /
//                              /
//==============================/



//==============================/
//                              /
// table group                  /
//                              /
//==============================/



//==============================/
//                              /
// table                        /
//                              /
//==============================/



//==============================/
//                              /
// user table                   /
//                              /
//==============================/



//==============================/
//                              /
// module                       /
//                              /
//==============================/


// Total Word Count = 0

#line 1 "./Tables.mpp"
///////////////////////////////////////////////////////////////////////////
// Output tables:  tables.mpp                                            //
///////////////////////////////////////////////////////////////////////////

/* NOTE(Tables, EN)
	This module contains all table definitions of RiskPaths.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Partitions

//EN Fertile age partition





///////////////////////////////////////////////////////////////////////////
// Tables

//EN Life Expectancy


//EN Total simulated cases
//EN Total duration
//EN Life expectancy decimals=3



//EN Life table

//EN Age


//EN Population start of year
//EN Average population in year




//EN Age-specific fertility  

//EN Age


//EN First birth rate all women decimals=4


//EN First birth rate woman at risk decimals=4





//EN Fertility rates by age group



//EN Fertility decimals=4

//EN Age interval
//EN Union Status


//EN Cohort fertility 


//EN Av. age at 1st pregnancy decimals=2



//EN Childlessness decimals=4


//EN Percent one child decimals=4




//EN Pregnancies by union status & order



//EN Number of pregnancies

//EN Union Status at pregnancy


//EN First union formation 


//EN Age group 


//EN First union formation risk decimals=4





///////////////////////////////////////////////////////////////////////////
// Table groups

//EN Life tables 




//EN Fertility 




//EN Unions 




#endif // Hide non-C++ syntactic island from IDE

#line 1 "./Tracking.mpp"
///////////////////////////////////////////////////////////////////////////
// Tracking.mpp                                                          //
///////////////////////////////////////////////////////////////////////////

/* NOTE(Tracking, EN)
	This module defines the states for BioBrowser tracking.
	Hazard rates calculated in this module as derived states
	are used for tracking purposes only.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE



//EN Pregnancy hazard




//EN Union formation hazard






//EN Union dissolution hazard





















	

#endif // Hide non-C++ syntactic island from IDE

#line 1 "./Unions.mpp"
///////////////////////////////////////////////////////////////////////////
// Union formation & dissolution events: unions.mpp                      //
///////////////////////////////////////////////////////////////////////////

/* NOTE(Unions, EN)
	This module simulates first and second union formations and 
	first and second union dissolutions.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Parameter definitions

//EN Duration of current union




//EN Duration since union dissolution




//EN Union order

//EN First union 				
//EN Second union 				





//EN Age baseline for first union formation


//EN Union Duration Baseline of Dissolution


//EN Separation Duration Baseline of 2nd Formation



//EN Union parameters 




///////////////////////////////////////////////////////////////////////////
// Actor states and event definitions



//EN Union counter


//EN Union status


//EN Currently in an union 




//EN Time interval since union formation



//EN Time interval since union dissolution





//EN Time of union period change


//EN First union formation event


//EN First union dissolution event


//EN Second union dissolution event


//EN Second union formation event 


//EN Union period change event 

  

#endif // Hide non-C++ syntactic island from IDE

///////////////////////////////////////////////////////////////////////////
// Clock event implementation


/*NOTE(Person.UnionPeriod2Event, EN)
	Clock event which changes the union duration state union_status from
	US_FIRST_UNION_PERIOD1 to US_FIRST_UNION_PERIOD2. This event occurs 
	after 3 years in 1st union. The clock is set at first union formation.
*/
TIME Person::timeUnionPeriod2Event()		
{
	return union_period2_change;
}
											
void Person::UnionPeriod2Event()			
{
	if (union_status == US_FIRST_UNION_PERIOD1)
	{
		union_status = US_FIRST_UNION_PERIOD2; 
	}
	union_period2_change = TIME_INFINITE;
}

///////////////////////////////////////////////////////////////////////////
// Event implementation

/*NOTE(Person.Union1FormationEvent, EN)
	The first union formation event. Union events are only simulated for 
	childless women, as pregnancy censors the union career.
*/
TIME Person::timeUnion1FormationEvent()							
{
	double	dHazard = 0;
	TIME 	event_time = TIME_INFINITE;

	if (union_status == US_NEVER_IN_UNION && parity_status == PS_CHILDLESS)		
	{
		dHazard = AgeBaselineForm1[age_status];	
		if (dHazard > 0)
		{
			event_time = WAIT(-log(RandUniform(4)) / dHazard);						
		}
	}
	return event_time;											
}

void Person::Union1FormationEvent()								
{
	unions++;													
	union_status = US_FIRST_UNION_PERIOD1;						
	union_period2_change = WAIT(3);
} 

/*NOTE(Person.Union2FormationEvent, EN)
	The second union formation event. Union events are only simulated for 
	childless women, as pregnancy censors the union career.
*/
TIME Person::timeUnion2FormationEvent()							
{
	double	dRandDur = 0, dHazard = 0;
	TIME 	event_time = TIME_INFINITE;

	if (union_status == US_AFTER_FIRST_UNION && parity_status == PS_CHILDLESS) 		
	{
		dHazard = SeparationDurationBaseline[dissolution_duration];	
		if (dHazard > 0)
		{
			dRandDur = -log(RandUniform(7)) / dHazard;			
			event_time = WAIT(dRandDur);						
		}
	}
	return event_time;											
}


void Person::Union2FormationEvent()								
{
	unions++;													
	union_status = US_SECOND_UNION;								
}

/*NOTE(Person.Union1DissolutionEvent, EN)
	The first union dissolution event. Union events are only simulated for 
	childless women, as pregnancy censors the union career.
*/
TIME Person::timeUnion1DissolutionEvent()						
{
	double	dHazard = 0;
	TIME	event_time = TIME_INFINITE;

	if ((union_status == US_FIRST_UNION_PERIOD1 || 
		union_status == US_FIRST_UNION_PERIOD2) && parity_status == PS_CHILDLESS)		
	{
		dHazard = UnionDurationBaseline[UO_FIRST][union_duration];	
		if (dHazard > 0)
		{
			event_time = WAIT(-log(RandUniform(5)) / dHazard);						
		}
	}
	return event_time;											
}

void Person::Union1DissolutionEvent()							
{
	union_status = US_AFTER_FIRST_UNION;						
} 

/*NOTE(Person.Union2DissolutionEvent, EN)
	The second union dissolution event. Union events are only simulated for 
	childless women, as pregnancy censors the union career.
*/
TIME Person::timeUnion2DissolutionEvent()						
{
	double	dHazard = 0;
	TIME	event_time = TIME_INFINITE;

	if (union_status == US_SECOND_UNION && parity_status == PS_CHILDLESS) 		
	{
		dHazard = UnionDurationBaseline[UO_SECOND][union_duration];	
		if (dHazard > 0)
		{
			event_time = WAIT(-log(RandUniform(6)) / dHazard);						
		}
	}
	return event_time;											
}

void Person::Union2DissolutionEvent()	
{
	union_status = US_AFTER_SECOND_UNION;
} 



#line 1 "./ompp_framework.ompp"
// Copyright (c) 2013-2014 OpenM++
// This code is licensed under MIT license (see LICENSE.txt for details)

//LABEL(ompp_framework, EN) OpenM++ simulation framework

/* NOTE(ompp_framework, EN)
	This module specifies the simulation framework
    and supplies function definitions required by the framework.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

// The following modules will be compiled and assembled in this order
// after all model-specific modules.






//options resource_use = on;

#endif // Hide non-C++ syntactic island from IDE

#line 1 "./ompp_options.ompp"
// Copyright (c) 2024-2024 OpenM++ Contributors
// This code is licensed under the MIT license (see LICENSE.txt for details)

//LABEL(ompp_options.ompp, EN) OpenM++ model options
//LABEL(ompp_options.ompp, FR) Options de modèle d'OpenM++

/* NOTE(ompp_options.ompp, EN)
    This module contains some commonly modified OpenM++ model options.
*/
/* NOTE(ompp_options.ompp, FR)
    Ce module contient des options de modèle d'OpenM++ souvent modifiées.
*/

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE

//
// General options
//

 // Create lifecycle_event and lifecycle_counter for Person entities


// 
// Microdata options:
//







// 
// Model Documentation options:
//  (These have no effect if Model Documentation is disabled in build settings.)
//

//options authored_documentation = off;    // Uncomment to suppress the autonomous authored component.
//options generated_documentation = off;   // Uncomment to suppress the generated Symbol Reference component.

// 
// Selected Symbol Reference options:
//

       // Uncomment to produce the Developer Edition instead of the User Edition.
 // Uncomment for models with small parameter hierarchies.
     // Uncomment for models with small table hierarchies.

#endif // Hide non-C++ syntactic island from IDE

#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/common.ompp"
/**
* @file    common.ompp
* Implementation of global functions for all models
* 
* The global functions in this module are declared in omSimulation.h.
* 
*/
// Copyright (c) 2013-2017 OpenM++ Contributors
// This code is licensed under the MIT license (see LICENSE.txt for details)

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE


//EN Simulation starting seed



#endif // Hide non-C++ syntactic island from IDE

/*NOTE(SimulationSeed,EN)
`SimulationSeed` determines the starting seeds of all random number generators in the run.
It is an integer greater than 0 and normally less than 2147483648.
Values larger than 2147483648 are reserved to reproduce a single selected member.
*/

//LABEL(SimulationSeed,FR) Graine de nombre aléatoire de la simulation

/*NOTE(SimulationSeed,FR)
`SimulationSeed` détermine les valeurs initiales de départ de tous les générateurs de nombres aléatoires de l'exécution.
Il s'agit d'un entier supérieur à 0 et normalement inférieur à 2147483648.
Les valeurs supérieures à 2147483648 sont réservées à la reproduction d'un seul membre sélectionné.
*/

//LABEL(bool,EN) boolean
/*NOTE(bool,EN)
A symbol of type `bool` has one of two values, `true` or `false`. 
A `bool` can be used in a numeric context, in which case `true` is `1` and `false` is `0`. 
A `bool` can also be used like a classification, 
for example as a dimension of a parameter or table.
*/

//LABEL(bool,FR) booléen
/*NOTE(bool,FR)
Un symbole de type `bool` a l'une des deux valeurs suivantes, `true` ou `false`. 
Un `bool` peut être utilisé dans un contexte numérique, auquel cas `true` est `1` et `false` est `0`. 
Un `bool` peut également être utilisé comme une classification, 
par exemple comme dimension d'un paramètre ou tableau.
*/

/**
* Called before model PreSimulation functions.
*/
void before_presimulation(int mem_id, int mem_count)
{
    extern void before_presimulation_for_framework(void);

    // code block for member and member count
    {
        // The number of member simulations in the sample of simulations
        fmk::simulation_members = mem_count;

        // The member to simulate of the sample of simulations
        fmk::simulation_member = mem_id;
    }

    // code block for SimulationSeed
    {
        if (SimulationSeed <= 0) {
            auto msg = openm::formatToString(LT("Error - SimulationSeed '%lld' must be greater than 0"), SimulationSeed);
            ModelExit(msg.c_str());
        }
        // Factor the combined seed SimulationSeed into its two parts
        fmk::SimulationSeed_member_part = SimulationSeed / ((long long)fmk::lcg_modulus + 1);
        fmk::SimulationSeed_seed_part = SimulationSeed - ((long long)fmk::lcg_modulus + 1) * fmk::SimulationSeed_member_part;
    }

    // Code block for random number support in PreSimulation
    {
        // In PreSimulation, the master seed is the same for all simulation members.
        // For lcg-style generators, a different generator is used for each member.
        // For other generators, the actual starting seed is generated from the master seed
        // and the simulation member number.
        fmk::master_seed = (int)fmk::SimulationSeed_seed_part;

        // Create stream generator objects
        // new_streams is generator-specific - defined in random/random_YYY.ompp
        new_streams();

        // Note that streams vary by simulation_member, master_seed and stream number.
        initialize_model_streams(); //defined in common.ompp
    }

    // Framework-specific before PreSimulation code
    before_presimulation_for_framework();
}

/**
* Called after invocation of PreSimulation functions.
*/
void after_presimulation()
{
    extern void after_presimulation_for_framework();

    // Code block for random number support in PreSimulation (cleanup)
    {
        fmk::master_seed = 0;

        // Free stream generator objects
        // delete_streams is generator-specific - defined in random/random_YYY.ompp
        delete_streams();
    }

    // Framework-specific after PreSimulation code
    after_presimulation_for_framework();
}

/**
 * Gets the combined seed.
 * 
 * Returns long long instead of double returned by GetCaseSeed()
 * For case-based models, the case seed, for time-based models, the global seed.
 * For both, the simulation member is encoded in high order bits.
 *
 * @return The seed, with the simulation member in high order bits
 */
long long get_combined_seed()
{
    return fmk::combined_seed;
}

/**
 * Gets the global time.
 * 
 * This global function can be used without #include of Event.h
 * 
 * @return The global time
 */
double get_global_time()
{
    return (double)BaseEvent::get_global_time();
}

/**
 * Initializes the model stream generators
 *
 * For case-based models, the stream generators are initialized for each case.
 * For time-based models, the stream generators are initialized for each member (aka replicate)
 */
void initialize_model_streams()
{
    // Note:
    //  fmk::master_seed is the run seed for time-based models
    //  fmk::master_seed is the case seed for case-based models
    long stream_seed = fmk::master_seed;
    for (int model_stream = 0; model_stream < fmk::size_streams; model_stream++) {
        // initialize_stream is generator-specific - defined in random/random_YYY.ompp.
        // Note that streams vary by simulation_member as well as stream_seed.
        initialize_stream(model_stream, fmk::simulation_member, stream_seed);
		// Use fixed integral-congruential generator (with multiplier model_stream_seed_generator)
		// to create seeds for streams.
        long long product = fmk::model_stream_seed_generator;
        product *= stream_seed;
        stream_seed = product % fmk::lcg_modulus;
    }
}

/**
 * Handles situation where time is running backwards within an entity.
 * 
 * An event about to be implemented in an entity has a time in the local past of the entity
 */
void handle_backwards_time(
    double the_current_time,
    double the_event_time,
    int the_event,
    int the_entity)
{
    // The time of this event is in the local past of the entity within which the event occurs.
    // This is caused by an error in model logic.
    std::stringstream ss;
    ss  << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << LT("error : Event time ") << std::showpoint << the_event_time
        << LT(" is earlier than current time ") << the_current_time
        << LT(" in event ") << omr::event_id_to_name(the_event)
        << LT(" in entity_id ") << the_entity
        << LT(" in simulation member ") << get_simulation_member()
        << LT(" with combined seed ") << get_combined_seed()
        ;
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where an entity attempts to access another entity in the local future.
 */
void handle_clairvoyance(
    double the_current_time,
    double the_future_time,
    int the_future_entity
    )
{
    // This is caused by an error in model logic.
    std::stringstream ss;
    ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << std::showpoint // show decimal point
        << LT("error : Attempt to access entity_id ") << the_future_entity
        << LT(" with future time ") << the_future_time
        << LT(" when current time is ") << the_current_time
        << LT(" after event ") << omr::event_id_to_name(BaseEvent::current_event_id)
        << LT(" in entity_id ") << BaseEvent::current_entity_id
        << LT(" in simulation member ") << get_simulation_member()
        << LT(" with combined seed ") << get_combined_seed()
        ;
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where model code attempts to derefence a null pointer to an entity
 */
void handle_null_dereference(
)
{
    // This is caused by an error in model logic.
    std::stringstream ss;
    ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << std::showpoint; // show decimal point
    ss << LT("Attempt to dereference null pointer");
    ss << LT(" when current time is ") << get_global_time();
    if (BaseEvent::current_entity_id >= 0) {
        ss << LT(" in entity_id ") << BaseEvent::current_entity_id;
    }
    if (BaseEvent::current_event_id >= 0) {
        ss << LT(" in or after event ") << omr::event_id_to_name(BaseEvent::current_event_id);
    }
    ss << LT(" in simulation member ") << get_simulation_member();
    ss << LT(" with combined seed ") << get_combined_seed();
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where model code attempts to modify an attribute when prohibited
 */
void handle_prohibited_attribute_assignment(
    const std_string name
)
{
    std::stringstream ss;
    ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << std::showpoint; // show decimal point
    ss << LT("Attempt to modify the attribute ");
    ss << name;
    ss << LT(" by the event time function of event ");
    ss << omr::event_id_to_name(BaseEvent::timefunc_event_id);
    ss << LT(" in entity_id ") << BaseEvent::timefunc_entity_id;
    ss << LT(" when current time is ") << get_global_time();
    if (BaseEvent::current_event_id >= 0) {
        ss << LT(" after event ") << omr::event_id_to_name(BaseEvent::current_event_id);
    }
    else {
        ss << LT(" before enter_simulation");
    }
    if (BaseEvent::current_entity_id >= 0) {
        ss << LT(" in entity_id ") << BaseEvent::current_entity_id;
    }
    ss << LT(" in simulation member ") << get_simulation_member();
    ss << LT(" with combined seed ") << get_combined_seed();
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where model code attempts to access a time-like attribute when prohibited
 */
void handle_prohibited_timelike_attribute_access(
    const std_string name
)
{
    std::stringstream ss;
    ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << std::showpoint; // show decimal point
    ss << LT("Attempt to access the time-like attribute ");
    ss << name;
    ss << LT(" by the event time function of event ");
    ss << omr::event_id_to_name(BaseEvent::timefunc_event_id);
    ss << LT(" in entity_id ") << BaseEvent::timefunc_entity_id;
    ss << LT(" when current time is ") << get_global_time();
    if (BaseEvent::current_event_id >= 0) {
        ss << LT(" after event ") << omr::event_id_to_name(BaseEvent::current_event_id);
    }
    else {
        ss << LT(" before enter_simulation");
    }
    if (BaseEvent::current_entity_id >= 0) {
        ss << LT(" in entity_id ") << BaseEvent::current_entity_id;
    }
    ss << LT(" in simulation member ") << get_simulation_member();
    ss << LT(" with combined seed ") << get_combined_seed();
    ModelExit(ss.str().c_str());
}

/**
 * Handle invalid table increment
 */
void handle_invalid_table_increment(
    double incr_value,
    const std_string table_name,
    const std_string attr_name
)
{
    std::stringstream ss;
    ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << std::showpoint; // show decimal point
    ss << LT("Invalid increment ");
    ss << incr_value;
    ss << LT(" in table '");
    ss << table_name;
    ss << LT("' using attribute '");
    ss << attr_name;
    if (BaseEvent::current_event_id >= 0) {
        ss << LT("' on or after event '") << omr::event_id_to_name(BaseEvent::current_event_id) << "'";
    }
    else {
        ss << LT(" before enter_simulation");
    }
    if (BaseEvent::current_entity_id >= 0) {
        ss << LT(" in entity_id ") << BaseEvent::current_entity_id;
    }
    ss << LT(" in simulation member ") << get_simulation_member();
    ss << LT(" with combined seed ") << get_combined_seed();
    ss << LT(" when current time is ") << get_global_time();
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where model code specifes an invalid number of indices to derived table API
 */
void handle_derived_table_API_invalid_rank(
    const char * name,
    size_t indices_rank,
    size_t indices_count
)
{
    std::stringstream ss;
    ss << LT("Derived table API - table ");
    ss << name;
    ss << LT(" has rank ");
    ss << indices_rank;
    ss << LT(" but number of indices is ");
    ss << indices_count;
    ss << LT(" in simulation member ") << get_simulation_member();
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where model code specifies an invalid index value to derived table API
 */
void handle_derived_table_API_invalid_index(
    const char* name,
    size_t index_position,
    size_t index_max,
    int index_value
)
{
    std::stringstream ss;
    ss << LT("Derived table API - table ");
    ss << name;
    ss << LT(" index ");
    ss << index_position;
    ss << LT(" must be in [0,");
    ss << index_max;
    ss << LT("] but is ");
    ss << index_value;
    ss << LT(" in simulation member ") << get_simulation_member();
    ModelExit(ss.str().c_str());
}

/**
 * Handles situation where model code attempts to assign an out-of-bouds value to a classifcation or range
 */
void handle_bounds_error(
    const std_string name,
    int min_value,
    int max_value,
    int value
)
{
    std::stringstream ss;
    ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
        << std::showpoint; // show decimal point
    ss << LT("attempt to assign ");
    ss << value;
    ss << LT(" to ");
    ss << name;
    ss << LT(" which has limits [");
    ss << min_value;
    ss << ",";
    ss << max_value;
    ss << "]";

    ss << LT(" when current time is ") << get_global_time();
    if (BaseEvent::current_entity_id >= 0) {
        ss << LT(" in entity_id ") << BaseEvent::current_entity_id;
    }
    if (BaseEvent::current_event_id >= 0) {
        ss << LT(" in or after event ") << omr::event_id_to_name(BaseEvent::current_event_id);
    }
    ss << LT(" in simulation member ") << get_simulation_member();
    ss << LT(" with combined seed ") << get_combined_seed();
    ModelExit(ss.str().c_str());
}

/**
 * Verify validity of array index
 *
 * @param   index  The index to check for validity.
 * @param   size   The size of the dimension.
 * @param   dim    The 0-based position of the dimension.
 * @param   symbol The name of the symbol.
 *
 * @returns index.
 */
int om_check_index(int index, int size, int dim, const char* name, const char* file, int line)
{
    if (index < 0 || index >= size) {
        // invalid array index, exit with runtime error message
        std::stringstream ss;
        ss << std::setprecision(std::numeric_limits<long double>::digits10 + 1) // maximum precision
            << std::showpoint; // show decimal point
        ss << LT("invalid index ");
        ss << index;
        ss << LT(" in 0-based dimension ");
        ss << dim;
        ss << LT(" of ");
        ss << name;
        ss << LT(" with bounds [0,");
        ss << size - 1;
        ss << "]";

        ss << LT(" when current time is ") << get_global_time();
        if (BaseEvent::current_entity_id >= 0) {
            ss << LT(" in entity_id ") << BaseEvent::current_entity_id;
        }
        if (BaseEvent::current_event_id >= 0) {
            ss << LT(" in or after event ") << omr::event_id_to_name(BaseEvent::current_event_id);
        }
        ss << LT(" in simulation member ") << get_simulation_member();
        ss << LT(" with combined seed ") << get_combined_seed();
        std::string fname = file;
        auto pos = fname.find_last_of("/\\");
        if ((pos != std::string::npos) && (pos + 1 < fname.length())) {
            fname = fname.substr(pos + 1);
        }
        ss << LT(" at module ") << fname;
        ss << "[" << line << "]";
        ModelExit(ss.str().c_str());
    }
    return index;
}

/**
 * Handles situation where the maximum random stream is exceeded.
 */
void handle_streams_exceeded(
    int strm, 
    int max_model_stream)
{
    // The stream number exceeds the maximum number of streams.
    std::stringstream ss;
    ss  << LT("error : stream number ") << strm
        << LT(" exceeds the maximum ") << max_model_stream << LT(".")
        ;
    ModelExit(ss.str().c_str());
}

/**
 * Gets total number of simulation members.
 *
 * @return The simulation members.
 */
int get_simulation_members()
{
    return fmk::simulation_members;
}

/**
 * Gets current simulation member.
 *
 * @return The simulation member.
 */
int get_simulation_member()
{
    return fmk::simulation_member;
}

/**
 * Gets the next entity identifier.
 * 
 * As a side-effect, increments the counter of entities in the simulation member. The entity_id
 * is constructed to be unique both within and across simulation members, with a minimum value
 * of 1.
 *
 * @return The next entity identifier.
 */
int get_next_entity_id()
{
    fmk::member_entity_counter++;
    return fmk::member_entity_counter * fmk::simulation_members + fmk::simulation_member;
}


/**
 * Fatal exit from the model, with a message.
 * 
 * See Modgen Developer's Guide for more information.
 */
void ModelExit(const char* msg)
{
    throw openm::SimulationException(msg);
}

/**
 * Report simulation progress.
 * 
 */
void report_simulation_progress(int member, int percent)
{
    theLog->logFormatted("member=%d Simulation progress=%d%%", member, percent);
    report_simulation_progress_beat(percent);
}

/**
 * Report simulation progress by sending it to database update thread.
 * 
 */
void report_simulation_progress_beat(int percent, double value)
{
    fmk::i_model->updateProgress(percent, value);
}

/**
 * Report parameters reading progress.
 */
int64_t report_parameter_read_progress(int paramNumber, int paramCount, const char * name, int64_t lastTime)
{
    int64_t now = getMilliseconds();
    if (now < lastTime + 5003) return lastTime;     // report not more often than every 5 seconds

    theLog->logFormatted("    %d of %d: %s", paramNumber, paramCount, name);
    return now;
}

/**
 * Report output tables writing progress.
 */
int64_t report_table_write_progress(int member, int tableNumber, const char * name, int64_t lastTime)
{
    int64_t now = getMilliseconds();
    if (now < lastTime + 5003) return lastTime;     // report not more often than every 5 seconds

    theLog->logFormatted("member=%d write table %d: %s", member, tableNumber, name);
    return now;
}

/**
 * In Modgen, displays a progress message in the UI.
 *
 * See Modgen Developer's Guide for more information.
 * Write the message to the log in ompp.
 * 
 * @param fmt The format string
 */
void ProgressMessage(const char* msg)
{
    theLog->logMsg(msg);
}

/**
 * In Modgen, communicates current simulation time to UI to display progress.
 *
 * See Modgen Developer's Guide for more information.
 * Not used in ompp.
 * 
 * @param tm The time.
 */
void TimeReport(double tm)
{
    // not implemented
}

/**
 * Set maximum time for fixed-precision time operations.
 * 
 * See Modgen Developer's Guide for more information.
 */
void SetMaxTime(double max_value)
{
    fixed_precision<Time::type>::set_max(max_value);
}

/**
 * Start event trace.
 * 
 * See Modgen Developer's Guide for more information.
 */
void StartEventTrace()
{
    if (om_event_trace_capable) {
        BaseEntity::event_trace_on = true;
    }
}

/**
 * Stop event trace.
 * 
 * See Modgen Developer's Guide for more information.
 */
void StopEventTrace()
{
    if (om_event_trace_capable) {
        BaseEntity::event_trace_on = false;
    }
}

/**
 * Total number of threads used in simulation.
 * 
 * See Modgen Developer's Guide for more information.
 */
int GetThreads()
{
    return 1;
}

/**
 * Numeric identifier of current thread for current simulation
 * 
 * See Modgen Developer's Guide for more information.
 */
int GetThreadNumber()
{
    return 1;
}

/**
 * Sets the total population used for population scaling
 *
 * @param lPopulation The total population.
 */
void SetPopulation(long lPopulation)
{
    fmk::set_population_value = lPopulation;
}

/**
 * Gets the total population used for population scaling
 *
 * @return The population.
 */
long GetPopulation()
{
    return fmk::set_population_value;
}

/**
 * Tells the framework to exit all entities from the simulation after completion of the current event.
 */
void signal_exit_simulation_all()
{
    fmk::do_exit_simulation_all = true;
}


/**
 * Piece linear lookup.
 *
 * @param x  The x coordinate.
 * @param ax The array of x coordinates of the points
 * @param ay The array of y coordinates of the points
 * @param n  The number of x-y points
 *
 * @return The y value corresponding to x
 */
double PieceLinearLookup(double x, const double *ax, const double *ay, int n)
{
    double y = 0.0;

    if (x <= ax[0]) {
        // X is less than lower bound of first interval, return Y of lower bound of first interval.
        y = ay[0];
    }
    else {
        // a simple linear search
        bool found = false;
        for (int j = 1; j < n; ++j) {
            if (!(ax[j] > ax[j - 1])) {
                // non-increasing X, throw error
                ModelExit("error : non-increasing x in PieceLinearLookup");
                // NOT_REACHED
            }
            if (x < ax[j]) {
                found = true;
                // interpolate
                y = ay[j - 1] + (ay[j] - ay[j - 1]) / (ax[j] - ax[j - 1]) * (x - ax[j - 1]);
                break;
            }
        }
        if (!found) {
            // X is greater than upper bound of last interval, return Y of upper bound of last interval.
            y = ay[n - 1];
        }
    }
    return y;
}

/**
 * Piece linear lookup (deprecated 3-argument version)
 *
 * @param x   The x coordinate.
 * @param axy The array of x-y coordinates of the points.
 * @param n   The number of values in axy (twice the number of points).
 *
 * @return The y value corresponding to x.
 */
double PieceLinearLookup(double x, const double *axy, int n)
{
    assert(0 == n % 2);
    // change n to number of points, to parallel logic in 4-argument version above
    n = n / 2;
    double y = 0.0;

    if (x <= axy[0]) {
        // X is less than lower bound of first interval, return Y of lower bound of first interval.
        y = axy[1];
    }
    else {
        // a simple linear search
        bool found = false;
        for (int j = 1; j < n; ++j) {
            int jx = 2 * j;    // index in axy of x of point j
            int jy = jx + 1;   // index in axy of y of point j
            int jx_p = jx - 2; // index in axy of x of point j-1
            int jy_p = jy - 2; // index in axy of y of point j-1
            if (!(axy[jx] > axy[jx_p])) {
                // non-increasing X, throw error
                ModelExit("error : non-increasing x in PieceLinearLookup");
                // NOT_REACHED
            }
            if (x < axy[jx]) {
                found = true;
                // interpolate
                y = axy[jy_p] + (axy[jy] - axy[jy_p]) / (axy[jx] - axy[jx_p]) * (x - axy[jx_p]);
                break;
            }
        }
        if (!found) {
            // X is greater than upper bound of last interval, return Y of upper bound of last interval.
            int jy = 2 * n - 1;
            y = axy[jy];
        }
    }
    return y;
}

/**
 * Process event trace options
 *
 * Called in RunInit
 */
void process_trace_options(IRunBase* const i_runBase)
{
    // Process model dev options for EventTrace
    if (om_event_trace_capable) { // is constexpr
        // Model was compiled with event trace capability

        theLog->logFormatted("Warning : possible performance impact - model built with event_trace = on");

        {
            std::string rptStyle = i_runBase->strOption("EventTrace.ReportStyle", "modgen");
            openm::toLower(rptStyle);
            if (rptStyle == "modgen") {
                BaseEntity::event_trace_report_style = BaseEntity::et_report_style::eModgen;
            }
            else if (rptStyle == "readable") {
                BaseEntity::event_trace_report_style = BaseEntity::et_report_style::eReadable;
            }
            else if (rptStyle == "csv") {
                BaseEntity::event_trace_report_style = BaseEntity::et_report_style::eCsv;
            }
            else {
                theLog->logFormatted("Warning : unrecognized EventTrace.ReportStyle=%s", rptStyle.c_str());
            }
        }

        BaseEntity::event_trace_show_events = true;
        if (i_runBase->isOptionExist("EventTrace.ShowEvents")) {
            BaseEntity::event_trace_show_events = i_runBase->boolOption("EventTrace.ShowEvents");
        }

        BaseEntity::event_trace_show_queued_events = false;
        if (i_runBase->isOptionExist("EventTrace.ShowQueuedEvents")) {
            BaseEntity::event_trace_show_queued_events = i_runBase->boolOption("EventTrace.ShowQueuedEvents");
        }

        BaseEntity::event_trace_show_queued_self_scheduling_events = false;
        if (i_runBase->isOptionExist("EventTrace.ShowQueuedSelfSchedulingEvents")) {
            BaseEntity::event_trace_show_queued_self_scheduling_events = i_runBase->boolOption("EventTrace.ShowQueuedSelfSchedulingEvents");
        }

        BaseEntity::event_trace_show_queued_unchanged = false;
        if (i_runBase->isOptionExist("EventTrace.ShowQueuedUnchanged")) {
            BaseEntity::event_trace_show_queued_unchanged = i_runBase->boolOption("EventTrace.ShowQueuedUnchanged");
        }

        BaseEntity::event_trace_show_enter_simulation = true;
        if (i_runBase->isOptionExist("EventTrace.ShowEnterSimulation")) {
            BaseEntity::event_trace_show_enter_simulation = i_runBase->boolOption("EventTrace.ShowEnterSimulation");
        }

        BaseEntity::event_trace_show_exit_simulation = true;
        if (i_runBase->isOptionExist("EventTrace.ShowExitSimulation")) {
            BaseEntity::event_trace_show_exit_simulation = i_runBase->boolOption("EventTrace.ShowExitSimulation");
        }

        BaseEntity::event_trace_show_self_scheduling_events = false;
        if (i_runBase->isOptionExist("EventTrace.ShowSelfSchedulingEvents")) {
            BaseEntity::event_trace_show_self_scheduling_events = i_runBase->boolOption("EventTrace.ShowSelfSchedulingEvents");
        }

        BaseEntity::event_trace_show_attributes = false;
        if (i_runBase->isOptionExist("EventTrace.ShowAttributes")) {
            BaseEntity::event_trace_show_attributes = i_runBase->boolOption("EventTrace.ShowAttributes");
        }

        BaseEntity::event_trace_show_table_increments = false;
        if (i_runBase->isOptionExist("EventTrace.ShowTableIncrements")) {
            BaseEntity::event_trace_show_table_increments = i_runBase->boolOption("EventTrace.ShowTableIncrements");
        }

        BaseEntity::event_trace_minimum_time = i_runBase->doubleOption("EventTrace.MinimumTime", -std::numeric_limits<double>::infinity());

        BaseEntity::event_trace_maximum_time = i_runBase->doubleOption("EventTrace.MaximumTime", std::numeric_limits<double>::infinity());

        BaseEntity::event_trace_minimum_age = i_runBase->doubleOption("EventTrace.MinimumAge", -std::numeric_limits<double>::infinity());

        BaseEntity::event_trace_maximum_age = i_runBase->doubleOption("EventTrace.MaximumAge", std::numeric_limits<double>::infinity());

        if (i_runBase->isOptionExist("EventTrace.SelectedEntityKinds")) {
            std::list<std::string> entList = openm::splitCsv(i_runBase->strOption("EventTrace.SelectedEntityKinds"));
            for (auto str : entList) {
                if (str.length() == 0) continue; // skip empty items in list
                BaseEntity::event_trace_selected_entity_kinds.insert(str);
            }
        }

        if (i_runBase->isOptionExist("EventTrace.SelectedEntities")) {
            std::list<std::string> entList = openm::splitCsv(i_runBase->strOption("EventTrace.SelectedEntities"));
            for (auto str : entList) {
                if (str.length() == 0) continue; // skip empty items in list
                int id = std::stoi(str);
                BaseEntity::event_trace_selected_entities.insert(id);
            }
        }

        if (i_runBase->isOptionExist("EventTrace.SelectedCaseSeeds")) {
            std::list<std::string> entList = openm::splitCsv(i_runBase->strOption("EventTrace.SelectedCaseSeeds"));
            for (auto str : entList) {
                if (str.length() == 0) continue; // skip empty items in list
                double val = std::stod(str);
                BaseEntity::event_trace_selected_case_seeds.insert(val);
            }
        }

        BaseEntity::event_trace_select_linked_entities = false;
        if (i_runBase->isOptionExist("EventTrace.SelectLinkedEntities")) {
            BaseEntity::event_trace_select_linked_entities = i_runBase->boolOption("EventTrace.SelectLinkedEntities");
            if (BaseEntity::event_trace_select_linked_entities && 0 == BaseEntity::event_trace_selected_entities.size()) {
                theLog->logFormatted("Warning : EventTrace.SelectedEntities is empty, ignoring EventTrace.SelectLinkedEntities");
                BaseEntity::event_trace_select_linked_entities = false;
            }
        }

        if (i_runBase->isOptionExist("EventTrace.SelectedEvents")) {
            std::list<std::string> evtList = openm::splitCsv(i_runBase->strOption("EventTrace.SelectedEvents"));
            for (auto str : evtList) {
                if (str.length() == 0) continue; // skip empty items in list
                int id = omr::event_name_to_id(str);
                if (id >= 0) {
                    BaseEntity::event_trace_selected_events.insert(id);
                }
                else {
                    theLog->logFormatted("Warning : unrecognized event EventTrace.SelectedEvents=%s", str.c_str());
                }
            }
        }

        if (i_runBase->isOptionExist("EventTrace.SelectedAttributes")) {
            std::list<std::string> attrList = openm::splitCsv(i_runBase->strOption("EventTrace.SelectedAttributes"));
            for (auto str : attrList) {
                if (str.length() == 0) continue; // skip empty items in list
                int id = omr::member_name_to_id(str);
                if (id >= 0) {
                    BaseEntity::event_trace_selected_attributes.insert(id);
                }
                else {
                    theLog->logFormatted("Warning : unrecognized attribute EventTrace.SelectedAttributes=%s", str.c_str());
                }
            }
        }

        BaseEntity::event_trace_minimum_attribute = i_runBase->doubleOption("EventTrace.MinimumAttribute", -std::numeric_limits<double>::infinity());

        BaseEntity::event_trace_maximum_attribute = i_runBase->doubleOption("EventTrace.MaximumAttribute", std::numeric_limits<double>::infinity());

        if (i_runBase->isOptionExist("EventTrace.SelectedTables")) {
            std::list<std::string> attrList = openm::splitCsv(i_runBase->strOption("EventTrace.SelectedTables"));
            for (auto str : attrList) {
                if (str.length() == 0) continue; // skip empty items in list
                int id = omr::table_name_to_id(str);
                if (id >= 0) {
                    BaseEntity::event_trace_selected_tables.insert(id);
                }
                else {
                    theLog->logFormatted("Warning : unrecognized table EventTrace.SelectedTables=%s", str.c_str());
                }
            }
        }

        BaseEntity::event_trace_name_column_width = i_runBase->intOption("EventTrace.NameColumnWidth", 40);

        BaseEntity::event_trace_maximum_lines = i_runBase->intOption("EventTrace.MaximumLines", 20000);
    }
    else {
        // Model was not compiled with event trace capability.
        // Ignore any EventTrace options.
    }
}

/**
* Helper code used internally by run-time
*
* The global definitions below are declared in helper.h.
*
*/
namespace omr {

    /**
    * model build environment to report at run time if user the model as: run model.exe -OpenM.Version
    *
    * - platform name: Windows 32 bit, Windows 64 bit, Linux or Apple (MacOS)
    * - configuration: Release or Debug
    * - MPI usage enabled or not
    */
#if !defined(_WIN32) && !defined(__linux__) && !defined(__APPLE__)
    const char * modelTargetOsName = "";
#else
    #ifdef _WIN32
        #ifdef _WIN64
            const char * modelTargetOsName = "Windows 64 bit";
        #else
            const char * modelTargetOsName = "Windows 32 bit";
        #endif
    #endif // _WIN32

    #ifdef __linux__
            const char * modelTargetOsName = "Linux";
    #endif

    #ifdef __APPLE__
        #include <TargetConditionals.h>
        #if defined(TARGET_OS_OSX) && TARGET_OS_OSX
           const char * modelTargetOsName = "macOS";
        #else
           const char * modelTargetOsName = "Apple OS";
        #endif
    #endif // __APPLE__
#endif

#ifdef NDEBUG
            const char * modelTargetConfigName = "Release";
#else
            const char * modelTargetConfigName = "Debug";
#endif // NDEBUG

#ifdef OM_MSG_MPI
            const char * modelTargetMpiUseName = "MPI";
#else
            const char * modelTargetMpiUseName = "";
#endif // OM_MSG_MPI
}

#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/common_modgen.ompp"
/**
* @file    modgen_common.ompp
* Functionality common to all kinds of Modgen models
* 
* The global functions in this module are documented in the header file omSimulation.h
* 
*/
// Copyright (c) 2013-2015 OpenM++
// This code is licensed under the MIT license (see LICENSE.txt for details)

namespace fmk {

} // namespace fmk
#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/random/random_lcg41.ompp"
/**
* @file    random_lcg41.ompp
* Implementation of framework for random number generation (Modgen's 41 linear congruential generators for streams)
*
* This version of the random number generation framework uses a set of 41 
* integral-congruential generators based on the Mersenne prime 2^31 - 1.
*
* The interface to models consists of the functions RandUniform, RandNormal, RandLogistic.
*
* The interface to framework modules, e.g. case_based_common.ompp consists of the functions
* new_streams, delete_streams, initialize_stream, serialize_random_state, deserialize_random_state
*
* Other content in this module should be considered to be 'private'.
*/
// Copyright (c) 2013-2022 OpenM++ Contributors
// This code is licensed under the MIT license (see LICENSE.txt for details)

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

namespace fmk {

    /**
     * The fixed number of random number stream generators available in Modgen.
     */
    const int max_stream_generators = 41;

    /**
     * Multiplier of generator used for a given simulation member.
     */
    const long model_stream_generators[max_stream_generators] = {
        16807,
        1826645050,
        519701294,
        1912518406,
        87921397,
        755482893,
        673205363,
        727452832,
        630360016,
        1142281875,
        219667202,
        200558872,
        1185331463,
        573186566,
        396907481,
        1106264918,
        1605529283,
        1902548864,
        1444095898,
        1600915560,
        1987505485,
        1323051066,
        1715488211,
        1289290241,
        967740346,
        1644645313,
        2142074246,
        1397488348,
        97473033,
        1210640156,
        990191797,
        640039787,
        1141672104,
        2081478048,
        1236995837,
        1985494258,
        84845685,
        184528125,
        1303680654,
        61496220,
        1096609123,
    };

    // Multiplier of the generator for the streams for this simulation (shared by all streams, varies by simulation member)
    thread_local long stream_generator = 0;

    // Current seed for each stream generator in the simulation
    thread_local long stream_seeds[size_streams];

    // Is there a random normal in other_normal?
    thread_local bool other_normal_valid[size_streams] = { false };

    // The other normal draw
    thread_local double other_normal[size_streams];

} // fmk

// Create objects for random streams
void new_streams()
{
	// no objects are used for Modgen random number streams
}

// Delete objects for random streams
void delete_streams()
{
	// no objects are used for Modgen random number streams
}

// Initialize a model stream
void initialize_stream(int model_stream, int member, long seed)
{
	// For members beyond number of Modgen generators, re-use generators cyclically.
	// Note that fmk::stream_generator is identical and shared for a simulation member.
	fmk::stream_generator = fmk::model_stream_generators[member % fmk::max_stream_generators];

    fmk::stream_seeds[model_stream] = seed;
    fmk::other_normal_valid[model_stream] = false;
}

/**
 * Serialize random state
 * 
 * The random state consists of seeds and Normal values for each stream.
 * These are converted to strings and pushed to the random_state.
 * If there is no random Normal available, an empty string is pushed.
 * 
 * @return A random_state.
 */
random_state serialize_random_state()
{
    random_state rs;
    rs.reserve(2 * fmk::size_streams);
    const size_t bufsize = 50;
    char wrk[bufsize];
    for (int j = 0; j < fmk::size_streams; ++j) {
        snprintf(wrk, bufsize, "%ld", fmk::stream_seeds[j]);
        rs.push_back(wrk);
        if (fmk::other_normal_valid[j]) {
            snprintf(wrk, bufsize, "%a", fmk::other_normal[j]);
        }
        else {
            // string of length 0 means no other normal for this stream
            wrk[0] = '\0';
        }
        rs.push_back(wrk);
    }
    return rs;
}

/**
 * Deserialize random state
 *
 * @param rs A previously saved random state to restore.
 */
void deserialize_random_state(const random_state & rs)
{
    for (int j = 0, k = 0; j < fmk::size_streams; ++j) {
        fmk::stream_seeds[j] = atol(rs[k++].c_str());
        auto wrk = rs[k++];
        fmk::other_normal_valid[j] = (wrk != "");
        if (fmk::other_normal_valid[j]) {
            fmk::other_normal[j] = atof(wrk.c_str());
        }
        else {
            fmk::other_normal[j] = 0.0; // value is irrelevant, never used
        }
    }
}

double RandUniform(int strm)
{
    assert(strm < fmk::size_streams);
    if (strm >= fmk::size_streams) {
        // The stream number exceeds the maximum number of streams.
        handle_streams_exceeded(strm, fmk::size_streams - 1);
        // not reached
    }

    long seed = fmk::stream_seeds[strm];
    long long product = fmk::stream_generator;
    product *= seed;
    seed = product % fmk::lcg_modulus;
    fmk::stream_seeds[strm] = seed;
    return (double)seed / (double)fmk::lcg_modulus;
}

double RandNormal(int strm)
{
    assert(strm < fmk::size_streams);
    if (strm >= fmk::size_streams) {
        // The stream number exceeds the maximum number of streams.
        handle_streams_exceeded(strm, fmk::size_streams - 1);
        // not reached
    }

    if (fmk::other_normal_valid[strm]) {
        fmk::other_normal_valid[strm] = false;
        return fmk::other_normal[strm];
    }
    else {
        double r2 = 1;
        double x = 0;
        double y = 0;
        while (r2 >= 1) {
            // unary + used to evade omc error detection of invalid stream
            x = 2.0 * RandUniform(+strm) - 1.0;
            y = 2.0 * RandUniform(+strm) - 1.0;
            r2 = x * x + y * y;
        }
        double scale = std::sqrt(-2.0 * std::log(r2) / r2);
        double n1 = scale * x;
        double n2 = scale * y;
        fmk::other_normal[strm] = n2;
        fmk::other_normal_valid[strm] = true;
        return n1;
    }
}

double RandLogistic(int strm)
{
    assert(strm < fmk::size_streams);
    if (strm >= fmk::size_streams) {
        // The stream number exceeds the maximum number of streams.
        handle_streams_exceeded(strm, fmk::size_streams - 1);
        // not reached
    }

    // unary + used to evade omc error detection of invalid stream
    double p = RandUniform(+strm);
    double odds_ratio = p / (1.0 - p);
    double x = std::log(odds_ratio);
    return x;
}


#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/case_based/case_based_lcg41.ompp"
/**
* @file    case_based_lcg41.ompp
* Modgen's 41 linear congruential generators for case seeds
*
*/
// Copyright (c) 2013-2015 OpenM++
// This code is licensed under the MIT license (see LICENSE.txt for details)

/**
 * The fmk namespace protects the global namespace for model use.
 */
namespace fmk {

	/**
	* The fixed number of random number stream case seed generators available in Modgen.
	*/
	const int max_case_seed_generators = 41;

	// Multiplier of generator used to generate the starting seeds for each case
    const long case_seed_generators[max_case_seed_generators] = {
        470583131,
        1278375574,
        1182424016,
        465267208,
        236156608,
        507096703,
        1030737213,
        1192442634,
        286354484,
        1963413634,
        929285805,
        1074439303,
        1866718706,
        1746251423,
        444178200,
        1076542630,
        289753891,
        490363125,
        803959450,
        37939113,
        1153920361,
        1010788020,
        1148043095,
        1422167303,
        1596996927,
        396692538,
        2125924067,
        290525234,
        1412033687,
        70608958,
        366654164,
        29727326,
        40186327,
        1271122795,
        940165244,
        735279377,
        1988769561,
        988683283,
        1943943356,
        1294875557,
        914624015,
    };

} // fmk


#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/case_based/case_based_common.ompp"
/**
* @file    case_based_common.ompp
* Implementation of framework for case-based models
*
*/
// Copyright (c) 2013-2020 OpenM++ Contributors
// This code is licensed under the MIT license (see LICENSE.txt for details)

// This module is for backwards compatibility after a code refactoring
// of 'use' modules.
// Preferably, the 'use' statement which included this module in ompp_framework.ompp
// should be replaced by the following use statements.




#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/case_based/case_based_scaling_none.ompp"
/**
* @file    case_based_scaling_none.ompp
* Implementation of population scaling
*
*/
// Copyright (c) 2013 OpenM++
// This code is licensed under the MIT license (see LICENSE.txt for details)

// forward declarations of fmk variables
namespace fmk {
    extern long long all_cases;
    extern thread_local long long member_cases;
}

/**
 * The population scaling factor to use for this member of the simulation.
 *
 * This version does no population scaling.
 * 
 * In tables, the size of the population reflects the number of total number of cases in the run.
 *
 * @return A double.
 */
double population_scaling_factor()
{
    return (double)fmk::all_cases / (double)fmk::member_cases;
}

#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/case_based/case_based_core.ompp"
/**
* @file    case_based_core.ompp
* Framework implementation for case-based models - core portions
*
*/
// Copyright (c) 2013-2021 OpenM++ Contributors (see AUTHORS.txt)
// This code is licensed under the MIT license (see LICENSE.txt for details)

/**
 * The fmk namespace protects the global namespace for model use.
 */
namespace fmk {

    /**
     * Helper function to output a case checksum message to the trace log.
     * 
     * @param case_seed     The case seed.
     * @param case_sample   The case sample.
     */
    void case_checksum_msg(double case_seed, int case_sample)
    {
        // The case checksum format reproduces the Modgen format precisely.
        theTrace->logFormatted("Case seed : %.0f\t-\tCase sample: %d\t-\tCheckSum : %.6f",
                           GetCaseSeed(),
                           case_sample,
                           BaseEvent::get_event_checksum());
    }

    /**
     * The total number of cases in the run (sum over all sample members).
     */
    long long all_cases = 0;

    /**
     * The number of cases to simulate in this member.
     */
    thread_local long long member_cases = 0;

    /**
     * The case counter in this simulation member.
     */
    thread_local long long member_case_counter = 0;

    /**
     * The case weight in this simulation member.
     */
    thread_local double member_case_weight = 1.0;

    /**
     * The sum of csae weights in this simulation member.
     */
    thread_local double member_sum_case_weight = 0.0;

} // namespace fmk

/**
 * Report simulation progress for case-based model.
 * 
 */
void report_simulation_progress(int member, int percent, long long cases)
{
    theLog->logFormatted("member=%d Simulation progress=%d%% cases=%lld", member, percent, cases);
    report_simulation_progress_beat(percent, (double)cases);
}

void SimulateEvents()
{
    // Simulate the case
    while (true) {
        if (!BaseEvent::do_next_event()) {
            // no more events
            break;
        }
    }
}

/**
 * Simulates the specified simulation (aka run) member
 *
 * @param mem_id    Identifier of the member to be simulated (sub-sample).
 * @param mem_count Total number of members (sub-samples).
 */
void RunSimulation(int mem_id, int mem_count, IModel * const i_model)
{
    // member count and current member previously assigned in before_simulation
    assert(fmk::simulation_members == mem_count);
    assert(fmk::simulation_member == mem_id);

    // The following functions are usually defined in the main simulation module, e.g. model.mpp
    // case_info is usually declared in the model-specific include file custom_early.h
    extern void Simulation_start(case_info &ci);
    extern void Simulation_end(case_info &ci);
    extern void CaseSimulation(case_info &ci);

    auto clock_time_start = std::chrono::system_clock::now();

    // note API object for subsequent use in modeling thread
    fmk::i_model = i_model;

    // Initialize the entity counter for this simulation member
    fmk::member_entity_counter = 0;

    // The member to simulate of the sample of simulations

    // if run option ProgressStep >0 then progress report must be done by number of cases completed
    // if run option ProgressPercent >0 then progress report must be done by percent completed
    // if none of above explicitly specified then progress report done by percent completed default value
    
    // for case based models progress step must be positive integer, if not zero default
    // casting between double and long long may produce incorrect result if value > 0x6fffffffffffffffi64
    bool is_step_progress = i_model->runOptions()->progressStep > 1.0;

    if (i_model->runOptions()->progressStep != 0.0  && 
        (i_model->runOptions()->progressStep < 1.0 || 
            i_model->runOptions()->progressStep > (double)0x3fffffffffffffffLL ||
            (i_model->runOptions()->progressStep - (long long)i_model->runOptions()->progressStep)) != 0.0) {
        is_step_progress = false;
        theLog->logFormatted("Warning: incorrect value of progress step reporting: %g", i_model->runOptions()->progressStep);
    }
    long long step_progress = is_step_progress ? (long long)i_model->runOptions()->progressStep : 0;

    // progress percent, if not zero, must be positive
    // if no options specified then by default do percent progress reporting
    bool is_percent_progress = i_model->runOptions()->progressPercent > 0;

    if (i_model->runOptions()->progressPercent < 0) {
        theLog->logFormatted("Warning: incorrect value of progress percent reporting: %d", i_model->runOptions()->progressPercent);
    }
    int percent_progress = is_percent_progress ? i_model->runOptions()->progressPercent : fmk::progress_percent_default;

    is_percent_progress |= !is_step_progress;   // by default report progress percent completed

    // next progress values to trigger reporting
    long long next_step_progress = step_progress;
    int next_percent_progress = percent_progress;
    bool is_100_percent_done = false;
    int64_t next_progress_beat = 0;
    int64_t next_ms_progress_beat = getMilliseconds() + OM_STATE_BEAT_TIME;

    report_simulation_progress(fmk::simulation_member, 0, 0);    // initial progress report 

    // Create the case information communication object
    case_info ci;

    // Initialize CaseInfo API
    CaseInfo(&ci);

	// Perform operations at the start of Simulation
	Simulation_start(ci);

    // For simulation member values greater than the number of lcg generators,
    // re-use case seed generators cyclically and increment the starting
    // master_seed for the simulation of the sample.
    fmk::master_seed = (int)fmk::SimulationSeed_seed_part + (int)fmk::simulation_member / fmk::max_case_seed_generators;
    long case_seed_generator = fmk::case_seed_generators[fmk::simulation_member % fmk::max_case_seed_generators];

	// Create stream generator objects
	// new_streams is generator-specific - defined in random/random_YYY.ompp
	new_streams();

    for (long long thisCase = 0; thisCase < fmk::member_cases; thisCase++) {

        initialize_model_streams(); //defined in common.ompp

        // Initial global time for the case
        BaseEvent::set_global_time(-time_infinite);

        // Initialize current entity and current event to -1 (none)
        BaseEvent::current_entity_id = -1;
        BaseEvent::current_event_id = -1;

        // record the encoded case seed (case_seed + simulation_member in high order bits)
        fmk::combined_seed = fmk::master_seed + fmk::simulation_member * ((long long)fmk::lcg_modulus + 1);

        // record the case counter within the current simulation member
        fmk::member_case_counter = thisCase;

        // Reset the running event checksum
        BaseEvent::event_checksum_reset();

        // Simulate the case
        CaseSimulation(ci);

        // Log the case checksum if activated
        if (BaseEvent::event_checksum_enabled) fmk::case_checksum_msg(fmk::master_seed, fmk::simulation_member);

        // Debug check for no left-over entities for which Finish was not called (possible model error)
        // TODO - consider making an optional warning activated by a model option
        //  which could be turned on/off.
        assert(0 == BaseEntity::om_active_entities());

        // cleanup entities and event queue after case has completed.
        BaseEntity::exit_simulation_all();
        BaseEvent::clean_all();
        BaseEntity::free_all_zombies();

        {
            // generate the master seed for the next case
            long long product = case_seed_generator;
            product *= fmk::master_seed;
            fmk::master_seed = product % fmk::lcg_modulus;
        }

        // Compute progress and report periodically
        {
            bool is_do_percent_progress = false;
            bool is_do_step_progress = false;

            int percent_done = (int)(100 * ((double)thisCase / (double)fmk::member_cases));

            if (is_percent_progress) {
                is_do_percent_progress = percent_done >= next_percent_progress;
                if (is_do_percent_progress) {
                    next_percent_progress = (percent_done / percent_progress) * percent_progress + percent_progress;
                }
            }
            if (!is_do_percent_progress && is_step_progress) {
                is_do_step_progress = thisCase >= next_step_progress;
                if (is_do_step_progress) {
                    next_step_progress = (thisCase / step_progress) * step_progress + step_progress;
                }
            }
            if (is_do_percent_progress || is_do_step_progress) {
                is_100_percent_done = percent_done >= 100;
                report_simulation_progress(fmk::simulation_member, percent_done, thisCase);
                next_progress_beat = 0;
                next_ms_progress_beat = getMilliseconds() + OM_STATE_BEAT_TIME;
            }
            else {
                if (++next_progress_beat > 1000) {
                    next_progress_beat = 0;
                    int64_t ms = getMilliseconds();
                    if (ms > next_ms_progress_beat) {
                        report_simulation_progress_beat(percent_done, (double)thisCase);
                        next_ms_progress_beat = ms + OM_STATE_BEAT_TIME;
                    }
                }
            }
        }
    } // cases

	// Perform operations at the end of Simulation
	Simulation_end(ci);

	// Free stream generator objects
	// delete_streams is generator-specific - defined in random/random_YYY.ompp
	delete_streams();

    // Reset CaseInfo API
    CaseInfo(nullptr, true);

    // final progress message
    if (!is_100_percent_done) {
        report_simulation_progress(fmk::simulation_member, 100, fmk::member_cases);
    }

    {
        // report simulation summary information for member
        auto clock_time_end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = clock_time_end - clock_time_start;
        double clock_time_delta = (double)elapsed_seconds.count();

        auto event_count = BaseEvent::global_event_counter;
        double events_per_case = (double)event_count / (double)fmk::member_cases;
        double entities_per_case = (double)fmk::member_entity_counter / (double)fmk::member_cases;
        // double seconds_per_case = clock_time_delta / (double)fmk::member_cases;
        theLog->logFormatted(
            "member=%d Simulation summary: cases=%lld, events/case=%.1f, entities/case=%.1f, elapsed=%.6fs",
            fmk::simulation_member,
            fmk::member_cases,
            events_per_case,
            entities_per_case,
            clock_time_delta
        );
    }
}

case_info* CaseInfo(case_info* ci, bool reset)
{
    static thread_local case_info* ci_stored = nullptr;

    if (reset) {
        ci_stored = nullptr;
    }
    else if (ci) {
        ci_stored = ci;
    }
    return ci_stored;
}

#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/case_based/case_based_modgen.ompp"
/**
* @file    case_based_modgen.ompp
* Framework implementation for case-based models - Modgen API
*
*/
// Copyright (c) 2013-2020 OpenM++ Contributors (see AUTHORS.txt)
// This code is licensed under the MIT license (see LICENSE.txt for details)


/**
 * Gets the numeric case identifier of the current case.
 * 
 * See Modgen Developer's Guide. The case identifier is unique, sequential, and starts at 0.
 * Values are interleaved among simulation members.  For example, if there are 4 simulation
 * members, member 0 would have case identifiers 0,4,8,... member 1 would have case identifiers 1,5,9,...
 *
 * @return The case identifier.
 */
long long GetCaseID()
{
    return fmk::member_case_counter * fmk::simulation_members + fmk::simulation_member;
}

/**
 * Gets the case seed of the current case (encoded with sample number).
 * 
 * See Modgen Developer's Guide.
 *
 * @return The case seed.
 */
double GetCaseSeed()
{
    return (double) get_combined_seed();
}

/**
 * Gets the sample number of the current case.
 *
 * See Modgen Developer's Guide.
 *
 * @return The case sample.
 */
int GetCaseSample()
{
    return fmk::simulation_member;
}

/**
 * Gets the sample number of the current call to UserTable
 *
 * See Modgen Developer's Guide.
 *
 * @return The case sample.
 */
int GetUserTableSubSample()
{
    return fmk::simulation_member;
}

/**
 * Gets the total number of cases, summed over all samples.
 *
 * See Modgen Developer's Guide.
 *
 * @return all cases.
 */
long long GetAllCases()
{
    return fmk::all_cases;
}

/**
 * Gets the number of "sub-samples" in the simulation.
 *
 * See Modgen Developer's Guide.
 *
 * @return The sub samples.
 */
int GetSubSamples()
{
    return fmk::simulation_members;
}

/**
 * Sets the weight of all entities in a case.
 * 
 * See Modgen Developer's Guide. Entity weighting is not yet implemented in ompp. A call to this
 * function will cause a run-time fatal error if weight is not equal to 1.0.
 *
 * @param weight The weight.
 */
void SetCaseWeight(double w)
{
    set_initial_weight(w);
}
void SetCaseWeight(double w, double w2)
{
    set_initial_weight(w);
}

/**
 * Gets case counter in thread.
 *
 * @return The case counter in thread.
 */
long long GetCaseCounterInThread()
{
    return fmk::member_case_counter;
}

void Set_actor_weight(double weight)
{
    // not implemented
    // TODO emit run-time warning once 
}

void Set_actor_subsample_weight(double weight)
{
    // not implemented
    // TODO emit run-time warning once 
}


#line 1 "C:/Users/parsaba/Desktop/1.17.6-patch/openmpp/bin/../use/case_based/case_based_cases_per_run_exogenous.ompp"
/**
* @file    case_based_cases_per_run.ompp
* Framework implementation for case-based models - SimulationCases gives number of cases for run (total over all members)
*
*/
// Copyright (c) 2013-2020 OpenM++ Contributors (see AUTHORS.txt)
// This code is licensed under the MIT license (see LICENSE.txt for details)

#include "omc/optional_IDE_helper.h" // help an IDE editor recognize model symbols

#if 0 // Hide non-C++ syntactic island from IDE


//EN Number of cases in run (over all members)



#endif // Hide non-C++ syntactic island from IDE

/*NOTE(SimulationCases, EN)
`SimulationCases` is the total number of cases in a run. 
If a run has multiple members, 
the cases are divided among the members 
as equally as possible.
*/

//LABEL(SimulationCases,FR) Nombre de cas dans tous les membres
/*NOTE(SimulationCases, FR)
`SimulationCases` est le nombre total de cas dans une exécution. 
Si une exécution a plusieurs membres, 
les cas sont répartis entre les membres 
le plus également que possible.
*/

/**
* Called by before_presimulation.
*/
void before_presimulation_for_framework(void)
{
    // Code block for number of cases
    {
        // For this style of model, the parameter SimulationCases
        // gives the number of cases in the run (over all members)
        fmk::all_cases = SimulationCases;

        if (fmk::SimulationSeed_member_part == 0) {
            // Normal run, start at member 0

            // The number of cases to simulate for this member.
            // Divide the total cases for the entire run by the number of members
            // and spread any cases in the remainder among the first members (one extra case each)
            fmk::member_cases = fmk::all_cases / fmk::simulation_members;
            if (fmk::simulation_member < (fmk::all_cases % fmk::simulation_members)) {
                fmk::member_cases++;
            };
        }
        else {
            // Special run, simulate a single case in the specified member.
            if (fmk::simulation_member == fmk::SimulationSeed_member_part) {
                // Simulate one case in the member specified in the combined seed
                fmk::member_cases = 1;
            }
            else {
                // Ignore all other members
                fmk::member_cases = 0;
            }
        }
    }
}

/**
* Called by after_presimulation.
*/
void after_presimulation_for_framework(void)
{
}
void Person::age_status_update_identity()
{
    #line 46 "./PersonCore.mpp"
    age_status.set(om_self_scheduling_split_FOR_age_X_AGEINT_STATE);
}
#line 3502 "om_developer.cpp"
void Person::dissolution_duration_update_identity()
{
    #line 72 "./Unions.mpp"
    dissolution_duration.set(om_self_scheduling_split_FOR_om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION_X_DISSOLUTION_DURATION);
}
#line 3508 "om_developer.cpp"
void Person::dissolution_hazard_update_identity()
{
    #line 30 "./Tracking.mpp"
    dissolution_hazard.set(((((union_status != US_FIRST_UNION_PERIOD1) && (union_status != US_FIRST_UNION_PERIOD2)) && (union_status != US_SECOND_UNION)) ? 0 : ((union_status == US_SECOND_UNION) ? UnionDurationBaseline[UO_SECOND][union_duration] : UnionDurationBaseline[UO_FIRST][union_duration])));
}
#line 3514 "om_developer.cpp"
void Person::formation_hazard_update_identity()
{
    #line 23 "./Tracking.mpp"
    formation_hazard.set((((union_status != US_NEVER_IN_UNION) && (union_status != US_AFTER_FIRST_UNION)) ? 0 : ((union_status == US_NEVER_IN_UNION) ? AgeBaselineForm1[age_status] : SeparationDurationBaseline[dissolution_duration])));
}
#line 3520 "om_developer.cpp"
void Person::in_union_update_identity()
{
    #line 63 "./Unions.mpp"
    in_union.set((((union_status == US_FIRST_UNION_PERIOD1) || (union_status == US_FIRST_UNION_PERIOD2)) || (union_status == US_SECOND_UNION)));
}
#line 3526 "om_developer.cpp"
void Person::integer_age_update_identity()
{
    #line 43 "./PersonCore.mpp"
    integer_age.set(COERCE(LIFE, om_self_scheduling_int_FOR_age));
}
#line 3532 "om_developer.cpp"
void Person::om_aia_0_update_identity()
{
    //#line This is a generated identity attribute which has no associated model source file
    om_aia_0.set((parity_status == PS_CHILDLESS));
}
#line 3538 "om_developer.cpp"
void Person::om_aia_1_update_identity()
{
    #line 85 "./Tables.mpp"
    om_aia_1.set(om_trigger_entrances_FOR_parity_status_X_PS_PREGNANT);
}
#line 3544 "om_developer.cpp"
void Person::om_aia_2_update_identity()
{
    //#line This is a generated identity attribute which has no associated model source file
    om_aia_2.set((union_status == US_NEVER_IN_UNION));
}
#line 3550 "om_developer.cpp"
void Person::om_aia_3_update_identity()
{
    //#line This is a generated identity attribute which has no associated model source file
    om_aia_3.set((in_union == true));
}
#line 3556 "om_developer.cpp"
void Person::om_aia_4_update_identity()
{
    //#line This is a generated identity attribute which has no associated model source file
    om_aia_4.set((union_status == US_AFTER_FIRST_UNION));
}
#line 3562 "om_developer.cpp"
#if defined (_MSC_VER)
	// Workaround to MSVC internal compiler error C1001 (BEGIN)
	#pragma optimize( "", off )
#endif
void Person::om_initialize_data_members()
{
    age.initialize( 0 );
    #line 46 "./PersonCore.mpp"
    age_status.initialize( 0 );
    case_id.initialize( 0 );
    case_seed.initialize( 0.0 );
    #line 72 "./Unions.mpp"
    dissolution_duration.initialize( 0 );
    #line 30 "./Tracking.mpp"
    dissolution_hazard.initialize( 0.0 );
    entity_id.initialize( 0 );
    #line 23 "./Tracking.mpp"
    formation_hazard.initialize( 0.0 );
    #line 63 "./Unions.mpp"
    in_union.initialize( false );
    #line 43 "./PersonCore.mpp"
    integer_age.initialize( 0 );
    #line 43 "./Mortality.mpp"
    life_status.initialize( LS_ALIVE );
    lifecycle_counter.initialize( 0 );
    lifecycle_event.initialize( LC_Person_enter_simulation );
    #line 44 "./Mortality.mpp"
    om_DeathEvent_om_event.initialize( time_infinite );
    #line 46 "./Fertility.mpp"
    om_FirstPregEvent_om_event.initialize( time_infinite );
    om_T01_LifeExpectancy_in_om_duration = 0;
    om_T02_TotalPopulationByYear_in_om_duration = 0;
    om_T03_FertilityByAge_in_om_duration = 0;
    om_T03_FertilityByAge_in_om_duration_FOR_parity_status_X_PS_CHILDLESS = 0;
    om_T03_FertilityByAge_in_om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT = 0;
    om_T04_FertilityRatesByAgeGroup_in_om_duration_FOR_parity_status_X_PS_CHILDLESS = 0;
    om_T04_FertilityRatesByAgeGroup_in_om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT = 0;
    om_T05_CohortFertility_in_om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT = 0;
    om_T05_CohortFertility_in_om_value_at_transitions_FOR_parity_status_X_PS_CHILDLESS_X_age_X_PS_PREGNANT = 0;
    om_T07_FirstUnionFormation_in_om_duration_FOR_union_status_X_US_NEVER_IN_UNION = 0;
    om_T07_FirstUnionFormation_in_om_entrances_FOR_union_status_X_US_FIRST_UNION_PERIOD1 = 0;
    #line 84 "./Unions.mpp"
    om_Union1DissolutionEvent_om_event.initialize( time_infinite );
    #line 81 "./Unions.mpp"
    om_Union1FormationEvent_om_event.initialize( time_infinite );
    #line 87 "./Unions.mpp"
    om_Union2DissolutionEvent_om_event.initialize( time_infinite );
    #line 90 "./Unions.mpp"
    om_Union2FormationEvent_om_event.initialize( time_infinite );
    #line 93 "./Unions.mpp"
    om_UnionPeriod2Event_om_event.initialize( time_infinite );
    om_active_spell_duration_FOR_in_union_X_true.initialize( 0 );
    om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION.initialize( 0 );
    om_aia_0.initialize( false );
    #line 85 "./Tables.mpp"
    om_aia_1.initialize( false );
    om_aia_2.initialize( false );
    om_aia_3.initialize( false );
    om_aia_4.initialize( false );
    om_duration.initialize( 0 );
    om_duration_FOR_parity_status_X_PS_CHILDLESS.initialize( 0 );
    om_duration_FOR_union_status_X_US_NEVER_IN_UNION.initialize( 0 );
    om_entrances_FOR_union_status_X_US_FIRST_UNION_PERIOD1.initialize( 0 );
    om_microdata_counter = 0;
    om_self_scheduling_int_FOR_age.initialize( 0 );
    om_self_scheduling_split_FOR_age_X_AGEINT_STATE.initialize( 0 );
    om_self_scheduling_split_FOR_age_X_AGE_FERTILEYEARS.initialize( 0 );
    om_self_scheduling_split_FOR_om_active_spell_duration_FOR_in_union_X_true_X_UNION_DURATION.initialize( 0 );
    om_self_scheduling_split_FOR_om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION_X_DISSOLUTION_DURATION.initialize( 0 );
    om_ss_time_om_self_scheduling_int_FOR_age = time_infinite;
    om_ss_time_om_self_scheduling_split_FOR_age_X_AGEINT_STATE = time_infinite;
    om_ss_time_om_self_scheduling_split_FOR_age_X_AGE_FERTILEYEARS = time_infinite;
    om_ss_time_om_self_scheduling_split_FOR_om_active_spell_duration_FOR_in_union_X_true_X_UNION_DURATION = time_infinite;
    om_ss_time_om_self_scheduling_split_FOR_om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION_X_DISSOLUTION_DURATION = time_infinite;
    om_ss_time_om_trigger_entrances_FOR_parity_status_X_PS_PREGNANT = time_infinite;
    om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT.initialize( 0 );
    om_trigger_entrances_FOR_parity_status_X_PS_PREGNANT.initialize( false );
    om_value_at_transitions_FOR_parity_status_X_PS_CHILDLESS_X_age_X_PS_PREGNANT.initialize( 0 );
    #line 42 "./Fertility.mpp"
    parity_status.initialize( PS_CHILDLESS );
    #line 18 "./Tracking.mpp"
    preg_hazard.initialize( 0.0 );
    time.initialize( 0 );
    #line 68 "./Unions.mpp"
    union_duration.initialize( 0 );
    #line 78 "./Unions.mpp"
    union_period2_change.initialize( time_infinite );
    #line 60 "./Unions.mpp"
    union_status.initialize( US_NEVER_IN_UNION );
    #line 57 "./Unions.mpp"
    unions.initialize( 0 );
    #line 39 "./Fertility.mpp"
    zzz_om_om_ss_event_om_event.initialize( time_infinite );

    // built-in attributes for a case-based model
    case_id.initialize(GetCaseID());
    case_seed.initialize(GetCaseSeed());
}
#if defined (_MSC_VER)
	// Workaround to MSVC internal compiler error C1001 (END)
	#pragma optimize( "", on )
#endif
#line 3665 "om_developer.cpp"
#if defined (_MSC_VER)
	// Workaround to MSVC internal compiler error C1001 (BEGIN)
	#pragma optimize( "", off )
#endif
void Person::om_initialize_data_members0()
{
    age.initialize( 0 );
    #line 46 "./PersonCore.mpp"
    age_status.initialize( 0 );
    case_id.initialize( 0 );
    case_seed.initialize( 0.0 );
    #line 72 "./Unions.mpp"
    dissolution_duration.initialize( 0 );
    #line 30 "./Tracking.mpp"
    dissolution_hazard.initialize( 0.0 );
    entity_id.initialize( 0 );
    #line 23 "./Tracking.mpp"
    formation_hazard.initialize( 0.0 );
    #line 63 "./Unions.mpp"
    in_union.initialize( false );
    #line 43 "./PersonCore.mpp"
    integer_age.initialize( 0 );
    #line 43 "./Mortality.mpp"
    life_status.initialize( LS_ALIVE );
    lifecycle_counter.initialize( 0 );
    lifecycle_event.initialize( LC_Person_enter_simulation );
    #line 44 "./Mortality.mpp"
    om_DeathEvent_om_event.initialize( time_infinite );
    #line 46 "./Fertility.mpp"
    om_FirstPregEvent_om_event.initialize( time_infinite );
    om_T01_LifeExpectancy_in_om_duration = 0;
    om_T02_TotalPopulationByYear_in_om_duration = 0;
    om_T03_FertilityByAge_in_om_duration = 0;
    om_T03_FertilityByAge_in_om_duration_FOR_parity_status_X_PS_CHILDLESS = 0;
    om_T03_FertilityByAge_in_om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT = 0;
    om_T04_FertilityRatesByAgeGroup_in_om_duration_FOR_parity_status_X_PS_CHILDLESS = 0;
    om_T04_FertilityRatesByAgeGroup_in_om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT = 0;
    om_T05_CohortFertility_in_om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT = 0;
    om_T05_CohortFertility_in_om_value_at_transitions_FOR_parity_status_X_PS_CHILDLESS_X_age_X_PS_PREGNANT = 0;
    om_T07_FirstUnionFormation_in_om_duration_FOR_union_status_X_US_NEVER_IN_UNION = 0;
    om_T07_FirstUnionFormation_in_om_entrances_FOR_union_status_X_US_FIRST_UNION_PERIOD1 = 0;
    #line 84 "./Unions.mpp"
    om_Union1DissolutionEvent_om_event.initialize( time_infinite );
    #line 81 "./Unions.mpp"
    om_Union1FormationEvent_om_event.initialize( time_infinite );
    #line 87 "./Unions.mpp"
    om_Union2DissolutionEvent_om_event.initialize( time_infinite );
    #line 90 "./Unions.mpp"
    om_Union2FormationEvent_om_event.initialize( time_infinite );
    #line 93 "./Unions.mpp"
    om_UnionPeriod2Event_om_event.initialize( time_infinite );
    om_active_spell_duration_FOR_in_union_X_true.initialize( 0 );
    om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION.initialize( 0 );
    om_aia_0.initialize( false );
    #line 85 "./Tables.mpp"
    om_aia_1.initialize( false );
    om_aia_2.initialize( false );
    om_aia_3.initialize( false );
    om_aia_4.initialize( false );
    om_duration.initialize( 0 );
    om_duration_FOR_parity_status_X_PS_CHILDLESS.initialize( 0 );
    om_duration_FOR_union_status_X_US_NEVER_IN_UNION.initialize( 0 );
    om_entrances_FOR_union_status_X_US_FIRST_UNION_PERIOD1.initialize( 0 );
    om_microdata_counter = 0;
    om_self_scheduling_int_FOR_age.initialize( 0 );
    om_self_scheduling_split_FOR_age_X_AGEINT_STATE.initialize( 0 );
    om_self_scheduling_split_FOR_age_X_AGE_FERTILEYEARS.initialize( 0 );
    om_self_scheduling_split_FOR_om_active_spell_duration_FOR_in_union_X_true_X_UNION_DURATION.initialize( 0 );
    om_self_scheduling_split_FOR_om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION_X_DISSOLUTION_DURATION.initialize( 0 );
    om_ss_time_om_self_scheduling_int_FOR_age = 0;
    om_ss_time_om_self_scheduling_split_FOR_age_X_AGEINT_STATE = 0;
    om_ss_time_om_self_scheduling_split_FOR_age_X_AGE_FERTILEYEARS = 0;
    om_ss_time_om_self_scheduling_split_FOR_om_active_spell_duration_FOR_in_union_X_true_X_UNION_DURATION = 0;
    om_ss_time_om_self_scheduling_split_FOR_om_active_spell_duration_FOR_union_status_X_US_AFTER_FIRST_UNION_X_DISSOLUTION_DURATION = 0;
    om_ss_time_om_trigger_entrances_FOR_parity_status_X_PS_PREGNANT = 0;
    om_transitions_FOR_parity_status_X_PS_CHILDLESS_X_PS_PREGNANT.initialize( 0 );
    om_trigger_entrances_FOR_parity_status_X_PS_PREGNANT.initialize( false );
    om_value_at_transitions_FOR_parity_status_X_PS_CHILDLESS_X_age_X_PS_PREGNANT.initialize( 0 );
    #line 42 "./Fertility.mpp"
    parity_status.initialize( PS_CHILDLESS );
    #line 18 "./Tracking.mpp"
    preg_hazard.initialize( 0.0 );
    time.initialize( 0 );
    #line 68 "./Unions.mpp"
    union_duration.initialize( 0 );
    #line 78 "./Unions.mpp"
    union_period2_change.initialize( 0 );
    #line 60 "./Unions.mpp"
    union_status.initialize( US_NEVER_IN_UNION );
    #line 57 "./Unions.mpp"
    unions.initialize( 0 );
    #line 39 "./Fertility.mpp"
    zzz_om_om_ss_event_om_event.initialize( time_infinite );
}
#if defined (_MSC_VER)
	// Workaround to MSVC internal compiler error C1001 (END)
	#pragma optimize( "", on )
#endif
#line 3764 "om_developer.cpp"
void Person::preg_hazard_update_identity()
{
    #line 18 "./Tracking.mpp"
    preg_hazard.set(((parity_status == PS_CHILDLESS) ? (AgeBaselinePreg1[age_status] * UnionStatusPreg1[union_status]) : 0));
}
#line 3770 "om_developer.cpp"
void Person::union_duration_update_identity()
{
    #line 68 "./Unions.mpp"
    union_duration.set(om_self_scheduling_split_FOR_om_active_spell_duration_FOR_in_union_X_true_X_UNION_DURATION);
}
#line 3776 "om_developer.cpp"
