#ifndef __VEHICLE_VAR_HH__
#define __VEHICLE_VAR_HH__
/********************************* TRICK HEADER *******************************
PURPOSE:
      (Vehicle variable definition)
LIBRARY DEPENDENCY:
      ((../src/Vehicle_var.cpp))
PROGRAMMERS:
      (((Chun-Hsu Lai) () () () ))
*******************************************************************************/

#include <armadillo>
#include <vector>
#include "aux.hh"
#include "body.hh"
#include "signal_process.hh"

enum STAGE { STAGE_1 = 0,
             STAGE_2 = 1,
             STAGE_3 = 2,
             FARING_SEP = 3 };
enum THRUST_TYPE { NO_THRUST = 0,
                   INPUT_THRUST = 3 };
enum TVC_TYPE {
    NO_TVC = 0,
    NO_DYNAMIC_TVC,
    SECON_ORDER_TVC,          // TVC Second order dynamics with rate limiting
    ONLINE_SECOND_ORDER_TVC,  // same as 2nd order but with on-line TVC gain
    S2_TVC,
    S3_TVC,
    S1_TVC
};



struct ENG_VAR {
    double ENG_mass;
    double ENG_mass0;
    double ENG_mass1;
    double ENG_isp;

    MATRIX(ENG_I, 3, 3);
    MATRIX(ENG_I_0, 3, 3);
    MATRIX(ENG_I_1, 3, 3);

    VECTOR(ENG_XCG, 3);
    VECTOR(ENG_XCG_0, 3);
    VECTOR(ENG_XCG_1, 3);
};

/* Stage variable */
class STAGE_VAR
{
public:
    STAGE_VAR();
    ~STAGE_VAR(){};
    double isp;            /* *o (--) Rocket engine's specific impluse */
    double fmass0;         /* ** (kg) Init fuel mass */
    double StageMass0;     /* ** (kg) Stage init mass */
    MATRIX(IBBB0, 3, 3);   /* *o (--) Initial vehicle's MOI */
    MATRIX(IBBB1, 3, 3);   /* *o (kg*m2) Final vehicle's MOI */
    VECTOR(XCG_0, 3);      /* *o (m) Initial vehicle's cg */
    VECTOR(XCG_1, 3);      /* *o (m) Final vehicle's cg */
    double fmasse;         /* *o (kg) Expended fuel mass */
    double fmassd;         /* ** (kg/s) Fuel mass expended derivative */
    double fuel_flow_rate; /* *o (kg/s) Fuel flow rate of engine */
    double aexit;          /* *o (m2) Engine nozzle area */
    double timer;          /* ** (s) Stage timer */
};

class Aerodynamics_var
{
public:
    Aerodynamics_var();
    ~Aerodynamics_var(){};
    double refa;  /* *o (m2)     Reference area for aero coefficients - m^2*/
    double refd;  /* *o (m)      Reference length for aero coefficients - m*/
    double cy;    /* *o (--)     Side force coefficient - ND*/
    double cll;   /* *o (--)     Rolling moment coefficient - ND*/
    double clm;   /* *o (--)     Pitching moment coefficient - ND*/
    double cln;   /* *o (--)     Yawing moment coefficient - ND*/
    double cx;    /* *o (--)     X-force coefficient - ND*/
    double cz;    /* *o (--)     Z-force coefficient - ND*/
    double cn;    /* *o (--)     Normal force coefficient */
    double ca;    /* *o (--)     Axial force coefficient */
    double ca_on; /* *o (--)     Axial force coefficient when engine is running */
    double cnq;   /* *o (--)     Normal damping coefficient */
    double cmq;   /* *o (--)     Pitch moment derivative coefficient */
    double ca0;
    double caa;
    double ca0b;
    double cn0;
    double clm0;
    double clmq;
    double cna;
    double clma;

    VECTOR(XCP,
           3); /* *o (m)      Non-dimensional center of pressure (from nose)*/
};

class EarthEnvironment_var
{
public:
    EarthEnvironment_var();
    ~EarthEnvironment_var(){};
    VECTOR(GRAVG, 3);  /* *o (m/s2) Earth gravity acceleration in inertia frame */
    VECTOR(VBAB, 3);   /* *o (m/s)  Vehicle speed wrt air speed in body frame */
    MATRIX(TEI, 3, 3); /* *o (--)  T.M. from ECI to ECEF */
    VECTOR(VAED, 3);

    double vmach;  /* *o (--)  vehicle mach number */
    double pdynmc; /* *o (pa)  Dynamic pressure */
    double dvba;   /* *o (m/s) Vehicle air speed magnitude */
    double gravg;  /* *o (m/s2)  Earth gravity acceleration magnitude */
    double tempc;  /* *o (c)  Atmosphere temperature in Celsius */
    double press;
    double tempk;
    double rho;
};

class DM_var
{
public:
    DM_var();
    ~DM_var(){};
    /* State variables */
    VECTOR(SBIIP, 3); /* *o  (m)      Vehicle position in inertia coord */

    VECTOR(VBIIP, 3); /* *o  (m/s)    Vehicle inertia velocity */

    VECTOR(WBIB, 3); /* *o (r/s)        Augular velocity of vehicle wrt inertia in
                     body coord */

    VECTOR(TBI_Q, 4); /* *o (--)    Transformation Matrix of body coord wrt
                      inertia coord (Quaternion) */

    VECTOR(NEXT_ACC, 3); /* *o (m/s2)   New Inertial acceleration */

    VECTOR(FAPB,
           3); /* *o (N)      Aerodynamic and propulsion forces in body axes */

    VECTOR(FAP, 3); /* *o (N)      Aerodynamic force in body axes */

    VECTOR(FMB,
           3); /* *o (N*m)    Aerodynamic and propulsion moment in body axes */

    VECTOR(FMAB,
           3); /* *o (N*m)    Aerodynamic and propulsion moment in body axes */

    VECTOR(Q_G, 6); /* *o (--)     External force generated by gravity */

    VECTOR(Q_Aero, 6); /* *o (--)  External force generated by aerodynamics */

    VECTOR(rhoC_1, 3); /* *o  (m)  Level arm from reference ponit to CG */

    MATRIX(I1, 3, 3); /* *o (kg*m2)  MOI of vehicle */

    VECTOR(ddrP_1, 3); /* *o  (m/s2)  Vehicle acceleration */

    VECTOR(ddang_1, 3); /* *o  (r/s2)  Vehicle angular acceleration */

    VECTOR(dang_1, 3); /* *o  (r/s)   Vehicle angular rate */

    VECTOR(ddrhoC_1, 3); /* *o  (m/s2)  Centrifugal acceleration and tangential
                          acceleration term */

    VECTOR(p_b1_ga,
           3); /* *o (--)   General dynamics equations 1st DoF to 3rd DoF */

    VECTOR(p_b1_be,
           3); /* *o (--)   General dynamics equations 4th DoF to 6th DoF */

    VECTOR(f, 6); /* *o  (--)  Summation of external force & internal force */

    VECTOR(gamma_b1_q1, 3); /* *o (--)  Vehicle's 1st DoF velocity coefficient */

    VECTOR(gamma_b1_q2, 3); /* *o (--)  Vehicle's 2nd DoF velocity coefficient */

    VECTOR(gamma_b1_q3, 3); /* *o (--)  Vehicle's 3rd DoF velocity coefficient */

    VECTOR(beta_b1_q4,
           3); /* *o (--)  Vehicle's 4th DoF angular velocity coefficient */

    VECTOR(beta_b1_q5,
           3); /* *o (--)  Vehicle's 5th DoF angular velocity coefficient */

    VECTOR(beta_b1_q6,
           3); /* *o (--)  Vehicle's 6th DoF angular velocity coefficient */

    /* Auxiliary variables */
    MATRIX(TBI, 3, 3); /* *o (--)    Transformation Matrix of body coord wrt
                    inertia coord */

    MATRIX(TBID, 3, 3); /* *o (--)    Transformation Matrix of body coord wrt
                     inertia coord derivative */

    VECTOR(TBID_Q, 4); /* *o (--)    Transformation Matrix of body coord wrt
                       inertia coord derivative (Quaternion) */

    MATRIX(TBD, 3, 3); /* *o (--)    Transformation Matrix of body coord wrt
                    geodetic coord */
    VECTOR(TBDQ, 4);   /* *o  (--)    Quaternion from geodetic to body */

    VECTOR(VBAB, 3); /* *o  (m/s)    Air speed in body frame */

    MATRIX(WEII_skew, 3,
           3); /* *o  (r/s)    Earth's angular velocity (skew-sym) */

    VECTOR(SBII, 3); /* *o  (m)      Vehicle position in inertia coord */

    VECTOR(VBII, 3); /* *o  (m/s)    Vehicle inertia velocity */

    VECTOR(ABII, 3); /* *o  (m/s2)   Vehicle inertia acceleration */

    VECTOR(ABIB,
           3); /* *o  (m/s2)   Vehicle inertia acceleration on body coordinate */

    VECTOR(SBEE, 3); /* *o  (m)     Vehicle position in earth coord  */

    VECTOR(VBEE, 3); /* *o  (m/s)     Vehicle speed in earth coord  */

    VECTOR(ABEE, 3); /* *o  (m/s2)   Vehicle acceleration in ECEF */

    VECTOR(SBEE_old, 3); /* *o  (m)     Vehicle position in earth coord  */

    VECTOR(VBEE_old, 3); /* *o  (m/s)     Vehicle speed in earth coord  */

    VECTOR(ABEE_old, 3); /* *o  (m/s2)   Vehicle acceleration in ECEF */

    VECTOR(JBII, 3); /* *o (m/s3)    Vehicle Jerk in ECI*/

    VECTOR(JBEE, 3); /* *o (m/s3)    Vehicle Jerk in ECEF */

    MATRIX(TDI, 3, 3); /* **  (--)     Transformation Matrix of geodetic wrt
                    inertial coordinates */

    MATRIX(
        TGI, 3,
        3); /* **  (--)     Transformation Matrix geocentric wrt inertia coord */

    VECTOR(VBED, 3); /* *o (m/s)   NED velocity */

    VECTOR(FSPB, 3); /* *o  (m/s2)   Specific force in body coord */

    MATRIX(TDE, 3, 3); /* ** (--)  T.M. from ECEF to geodetic */

    VECTOR(VBII_old, 3); /* ** (m/s)  Prior body inertia velocity */

    VECTOR(WEII, 3); /* ** (--)  Earth rate in inertia coordinate */

    VECTOR(WBII, 3); /* *o (r/s)        Vehicle's inertia angular velocity in
                     inertia coord */

    VECTOR(WBEB, 3); /* *o (r/s)        Angular velocity of vehicle wrt earth in
                     body coord */

    VECTOR(WBIBD, 3); /* *o (r/s2)       Angular velocity of vehicle wrt inertia
                      in body coord - derivative */

    MATRIX(TVD, 3, 3); /* **  (--)     Transformation Matrix of geographic
                    velocity wrt geodetic coord */

    VECTOR(SBEE_test, 3); /* *o  (m)     Vehicle position in earth coord  */

    VECTOR(VBEE_test, 3); /* *o  (m/s)     Vehicle speed in earth coord  */

    VECTOR(ABEE_test, 3); /* *o  (m/s2)   Vehicle acceleration in ECEF */

    MATRIX(TLI, 3, 3); /* **  (--)  T.M. from inertia to launch site */

    VECTOR(LT_euler, 3); /* ** (rad)  Launch site coordinate Euler angle */

    VECTOR(TBLQ, 4); /* ** (--) Quaternion from launch site to body */

    VECTOR(ABID, 3); /* ** (--) Vehicle inertia body acceleration in geodetic */

    VECTOR(Fg, 3);

    VECTOR(F_Aero, 3);

    VECTOR(M_Aero, 3);
    /* Generating Outputs */
    double
        ortho_error; /* *o (--)    Direction cosine matrix orthogonality error*/
    double alphax;   /* *o (d)     Angle of attack */
    double betax;    /* *o (d)     Sideslip angle */
    double alppx;    /* *o (d)     Total angle of attack */
    double phipx;    /* *o (d)     Aerodynamic roll angle*/
    double alphaix;  /* *o (d)     Angle of attack, inertia velocity*/
    double betaix;   /* *o (d)     Sideslip angle, inertia velocity*/
    double psibdx;   /* *o (d)     Yaw angle of Vehicle wrt geodetic coord - deg */
    double
        thtbdx;          /* *o (d)     Pitch angle of Vehicle wrt geodetic coord - deg */
    double phibdx;       /* *o (d)     Roll angle of Vehicle wrt geodetic coord - deg */
    double psibd;        /* *o (r)     Yaw angle of Vehicle wrt geodetic coord - rad */
    double thtbd;        /* *o (r)     Pitch angle of Vehicle wrt geodetic coord - rad */
    double phibd;        /* *o (r)     Roll angle of Vehicle wrt geodetic coord - rad */
    double alt;          /* *o  (m)      Vehicle altitude */
    double lonx;         /* *o  (d)      Vehicle longitude */
    double latx;         /* *o  (d)      Vehicle latitude */
    double _aero_loss;   /* *o  (m/s)    Velocity loss caused by aerodynamic drag */
    double gravity_loss; /* *o  (m/s)    Velocity loss caused by gravity */
    // double t;            /* *o (s)       timer */
    double _grndtrck;    /* *o  (m)     [DIAG] Vehicle ground track on earth */
    double _gndtrkmx;    /* *o  (km)    [DIAG] Ground track - km */
    double _gndtrnmx;    /* **  (nm)    [DIAG] Ground track - nm */
    double _ayx;         /* *o  (m/s2)  [DIAG] Achieved side acceleration */
    double _anx;         /* *o  (m/s2)  [DIAG] Achieved normal acceleration */
    double _dbi;         /* *o  (m)     [DIAG] Vehicle distance from center of earth */
    double _dvbi;        /* *o  (m/s)   [DIAG] Vehicle inertia speed */
    double _dvbe;        /* *o  (m/s)   [DIAG] Vehicle geographic speed */
    double _thtvdx;      /* *o  (d)     [DIAG] Vehicle's flight path angle */
    double _psivdx;      /* *o  (d)     [DIAG] Vehicle's heading angle */
    int liftoff;         /* *i  (--)     To check wether the rocket liftoff or
                              not: liftoff = 1, not liftoff = 0 */
    int cadorbin_flag;   /* Orbit calculation status flag */
    double ppx;          /* *o (d/s)        Body roll angular velocity wrt earth in body
                 axes */
    double qqx;          /* *o (d/s)        Body pitch angular velocity wrt earth in body
                 axes */
    double rrx;          /* *o (d/s)        Body yaw angular velocity wrt earth in body
                 axes */
    double control_loss; /* *o (--) Velocity loss due to control effect */

    /* Orbital Logging */
    double _inclination;    /* *o  (deg)   [DIAG] Orbital inclination is the minimun
                        angle between reference plane and the orbital plane or
                        direction of an object in orbit around another object */
    double _eccentricity;   /* *o  (--)    [DIAG] Determines the amount by which its
                           orbit around another body deviates from a perfect
                           circle */
    double _semi_major;     /* *o  (m)     [DIAG] the major axis of an ellipse is its
                         longest diameter */
    double _ha;             /* *o  (m)     [DIAG] Orbital Apogee */
    double _hp;             /* *o  (m)     [DIAG] Orbital Perigee */
    double _lon_anodex;     /* *o  (deg)   [DIAG] The longitude of the ascending node
                         (☊ or Ω) is one of the orbital elements used to specify
                         the orbit of an object in space. It is the angle from a
                         reference direction, called the origin of longitude, to
                         the direction of the ascending node, measured in a
                         reference plane */
    double _arg_perix;      /* *o  (deg)   [DIAG] The argument of periapsis (also
                         called argument of perifocus or argument of pericenter),
                         symbolized as ω, is one of the orbital elements of an
                         orbiting body. Parametrically, ω is the angle from the
                         body's ascending node to its periapsis, measured in the
                         direction of motion */
    double _true_anomx;     /* *o  (deg)   [DIAG] In celestial mechanics, true anomaly
                      is an angular parameter that defines the position of a
                      body moving along a Keplerian orbit. It is the angle
                      between the direction of periapsis and the current
                      position of the body, as seen from the main focus of the
                      ellipse (the point around which the object orbits) */
    double _ref_alt;        /* *o  (m)     [DIAG] */
    double reference_point; /* *o (m)    Multibody dynamics reference point */
    double Roll;
    double Pitch;
    double Yaw;
    unsigned int Interpolation_Extrapolation_flag;
    // double xp; /* *o (m) Reference point  */
    int its;                  /* *o (--) Number of iterations */
    int DOF;                  /* *o (--)  Number of Degree of Freedom */
    int reference_point_flag; /* *o (--)  check if reference point equal to xcg */
    unsigned int Aero_flag;   /* *o (-)  Aerodynamics flag */

    Body *Body_ptr;
};

class Prop_var
{
public:
    Prop_var();
    ~Prop_var(){};

    VECTOR(XCG, 3);      /* *o (m) Current vehicle's cg */
    MATRIX(IBBB, 3, 3);  /* *o (kg*m2) Current cheicle's MOI */
    double vmass;        /* *o (kg) Current vehicle mass */
    double fmassr;       /* *o (kg) Remaining fuel mass */
    double mass_ratio;   /* *o (--) fmasse / fmass0 */
    double payload_mass; /* *o (kg) Payload mass */
    double faring_mass;  /* *o (kg) Vehicle faring mass */
    double thrust;       /* *o (N) Thrust generated by vehicle's engine */
    double delta_v;      /* *o (m/s)  Vehicle delta-V generated by engine */

    /* State */
    enum THRUST_TYPE
        thrust_state; /* *o (--)     Propulsion mode, See THRUST TYPE*/
    enum STAGE stage;
};

class ACT_var
{
public:
    ACT_var();
    ~ACT_var(){};

    VECTOR(Q_RCS, 6);   /* ** (--)  External force generated by RCS thruster */
    double gtvc;        /* *o  (--)    TVC nozzle deflection gain n*/
    double theta_a_cmd; /* *o (r)  Store first actuator command */
    double theta_b_cmd; /* *o (r)  Store second actuator command */
    double theta_c_cmd; /* *o (r)  Store third actuator command */
    double theta_d_cmd; /* *o (r)  Store fourth actuator command */
    enum TVC_TYPE mtvc; /* *o  (--)      see TVC_TYPE */
    VECTOR(Q_TVC, 6);   /* *o (--) External force generated by the rocket engines */
    VECTOR(F_TVC, 3);
    VECTOR(M_TVC, 3);
};

class Sensor_var
{
public:
    Sensor_var();
    ~Sensor_var(){};

    //Accelerometer var
    VECTOR(FSPCB, 3); /* *o  (N/kg)  Computed specific force on body */

    VECTOR(EFSPB, 3);  /* *o   (N/kg)  Error in specific force on body in body
                      coordinate */
    VECTOR(EWALKA, 3); /* *o   (m/s2)  Acceleration random noise */

    VECTOR(EMISA, 3); /* *o   (r)     Acceleration misalignment */

    VECTOR(ESCALA, 3); /* *o   (--)    Acceleration scale factor */

    VECTOR(EBIASA, 3); /* *o   (m/s2)  Acceleration bias */

    VECTOR(ITA1_A, 3); /* *o   (--)  Random noise calculation variable */

    VECTOR(ITA2_A, 3); /* *o   (--)  Random noise calculation variable */

    VECTOR(BETA_A, 3); /* *o   (--)  Random noise calculation variable */

    // Gyro var
    VECTOR(WBICB, 3); /* *o  (r/s)   Computed inertial body rate in body coordinate */

    VECTOR(EWBIB, 3); /* *o  (r/s)   Error in angular vel of body wrt earth */

    VECTOR(EUG, 3); /* *o   (r/s)    Gyro spin axis accel sensitivity */

    VECTOR(EWG, 3); /* *o   (r/s)    Gyro random walk errors */

    VECTOR(EWALKG, 3); /* *o   (r/s0.5) Random walk */

    VECTOR(EUNBG, 3); /* *o   (r)      Gyro cluster misalignment */

    VECTOR(EMISG, 3); /* *o   (r)      Gyro misalignmt */

    VECTOR(ESCALG, 3); /* *o   (--)     Gyro scale factor */

    VECTOR(EBIASG, 3); /* *o   (r/s)    Gyro bias */

    VECTOR(ITA1_G, 3); /* *o   (--)  Coefficient of gyro noise calculation */

    VECTOR(ITA2_G, 3); /* *o   (--)  Coefficient of gyro noise calculation */

    VECTOR(BETA_G, 3); /* *o   (--)  Coefficient of gyro noise calculation */

    //SDT var
    VECTOR(PHI, 3); /* *o (r)       PHI = DELTA_ALPHA + 0.5 * DELTA_BETA */

    VECTOR(DELTA_VEL, 3); /* *o (m/s)     Delta V */

    unsigned int k; /* *o (--)       calculate index */

    VECTOR(WBISB, 3); /* *o  (r/s)    Angular rate of body frame relative inertial
                       frame as described in body frame sensed by gyro */

    VECTOR(WBISB_old,
           3); /* *o  (r/s)    Angular rate of body frame relative inertial frame
                as described in body frame (previous time step) */

    VECTOR(DELTA_ALPHA, 3); /* *o  (r)      Delta theta */

    VECTOR(DELTA_ALPHA_old, 3); /* *o (r)   Delta theta (previous time step) */

    VECTOR(ALPHA, 3); /* *o (r)       Alpha */

    VECTOR(FSPSB, 3); /* *o (m/s2)    Specific force of body frame sensed by
                       accelerometer */

    VECTOR(FSPSB_old, 3); /* *o  (m/s2)    Previous Specific force of body frame
                           sensed by accelerometer */

    VECTOR(cross2_old,
           3); /* *o (--)      temporal store the cross product result */

    VECTOR(VEL, 3); /* *o (m/s)     Delta velocity generated by Accelerometer
                     sensing value */
};
#endif  // __VEHICLE_VAR_HH__