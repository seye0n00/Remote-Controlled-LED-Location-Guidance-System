from flask import Flask, request, jsonify
from mqtt_pub import MqttPublisher
from config import MQTT_BROKER, MQTT_PORT, MQTT_PUB_TOPIC
import json
import time

app = Flask(__name__)

# MQTT publisher instance
mqtt_pub = MqttPublisher()
mqtt_pub.connect()
time.sleep(1)

@app.route("/led")
def led_control():
    
    #receive HTTP GET query parameter
    
    location = request.args.get("location")  # "A3"

    # ---- validation ----
    if not location or len(location) < 2:
        return jsonify({"result": "invalid location"}), 400

    edge = location[0]        # 'A'
    seg = int(location[1:])   # 3

    topic = f"{MQTT_PUB_TOPIC}/{edge}/cmd"
    payload = {
        "seg": seg
    }

    # Map HTTP parameter to MQTT message
    msg = json.dumps(payload)

    # Publish to MQTT
    success = mqtt_pub.publish(topic, msg)

    # Return execution result as JSON response
    return jsonify({
        "result" : "ok" if success else "fail",
        "location": location
    })

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)