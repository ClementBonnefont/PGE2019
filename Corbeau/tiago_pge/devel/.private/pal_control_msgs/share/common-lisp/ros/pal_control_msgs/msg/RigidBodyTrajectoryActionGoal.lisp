; Auto-generated. Do not edit!


(cl:in-package pal_control_msgs-msg)


;//! \htmlinclude RigidBodyTrajectoryActionGoal.msg.html

(cl:defclass <RigidBodyTrajectoryActionGoal> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (goal_id
    :reader goal_id
    :initarg :goal_id
    :type actionlib_msgs-msg:GoalID
    :initform (cl:make-instance 'actionlib_msgs-msg:GoalID))
   (goal
    :reader goal
    :initarg :goal
    :type pal_control_msgs-msg:RigidBodyTrajectoryGoal
    :initform (cl:make-instance 'pal_control_msgs-msg:RigidBodyTrajectoryGoal)))
)

(cl:defclass RigidBodyTrajectoryActionGoal (<RigidBodyTrajectoryActionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RigidBodyTrajectoryActionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RigidBodyTrajectoryActionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pal_control_msgs-msg:<RigidBodyTrajectoryActionGoal> is deprecated: use pal_control_msgs-msg:RigidBodyTrajectoryActionGoal instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RigidBodyTrajectoryActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pal_control_msgs-msg:header-val is deprecated.  Use pal_control_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'goal_id-val :lambda-list '(m))
(cl:defmethod goal_id-val ((m <RigidBodyTrajectoryActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pal_control_msgs-msg:goal_id-val is deprecated.  Use pal_control_msgs-msg:goal_id instead.")
  (goal_id m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <RigidBodyTrajectoryActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pal_control_msgs-msg:goal-val is deprecated.  Use pal_control_msgs-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RigidBodyTrajectoryActionGoal>) ostream)
  "Serializes a message object of type '<RigidBodyTrajectoryActionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal_id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RigidBodyTrajectoryActionGoal>) istream)
  "Deserializes a message object of type '<RigidBodyTrajectoryActionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal_id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RigidBodyTrajectoryActionGoal>)))
  "Returns string type for a message object of type '<RigidBodyTrajectoryActionGoal>"
  "pal_control_msgs/RigidBodyTrajectoryActionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RigidBodyTrajectoryActionGoal)))
  "Returns string type for a message object of type 'RigidBodyTrajectoryActionGoal"
  "pal_control_msgs/RigidBodyTrajectoryActionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RigidBodyTrajectoryActionGoal>)))
  "Returns md5sum for a message object of type '<RigidBodyTrajectoryActionGoal>"
  "6de73983bf902c676fada6dcd0891235")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RigidBodyTrajectoryActionGoal)))
  "Returns md5sum for a message object of type 'RigidBodyTrajectoryActionGoal"
  "6de73983bf902c676fada6dcd0891235")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RigidBodyTrajectoryActionGoal>)))
  "Returns full string definition for message of type '<RigidBodyTrajectoryActionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%RigidBodyTrajectoryGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: pal_control_msgs/RigidBodyTrajectoryGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%Header header~%~%# see PolynomialInterpolatorType~%int8    interpolation_type~%~%pal_control_msgs/RigidBodyTrajectoryPoint[]     trajectory~%~%================================================================================~%MSG: pal_control_msgs/RigidBodyTrajectoryPoint~%duration                duration~%~%geometry_msgs/Pose      pose~%geometry_msgs/Twist     velocity~%geometry_msgs/Accel     acceleration~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RigidBodyTrajectoryActionGoal)))
  "Returns full string definition for message of type 'RigidBodyTrajectoryActionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%RigidBodyTrajectoryGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: pal_control_msgs/RigidBodyTrajectoryGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%Header header~%~%# see PolynomialInterpolatorType~%int8    interpolation_type~%~%pal_control_msgs/RigidBodyTrajectoryPoint[]     trajectory~%~%================================================================================~%MSG: pal_control_msgs/RigidBodyTrajectoryPoint~%duration                duration~%~%geometry_msgs/Pose      pose~%geometry_msgs/Twist     velocity~%geometry_msgs/Accel     acceleration~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Accel~%# This expresses acceleration in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RigidBodyTrajectoryActionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal_id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RigidBodyTrajectoryActionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'RigidBodyTrajectoryActionGoal
    (cl:cons ':header (header msg))
    (cl:cons ':goal_id (goal_id msg))
    (cl:cons ':goal (goal msg))
))
