Phase 1: Sensor Mode Setup
  1. On setup, go into connect WiFi mode (ESPTouch)
  2. Connect to WiFi
     a. On fail, return error
     b. Restart connect WiFi mode (ESPTouch)
  3. Wait for POST request containing Firebase database URL
  4. When receive Firebase database URL, add a field in the database
  5. Update status in the database every minute
