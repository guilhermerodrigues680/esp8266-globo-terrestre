export function configDefaultTokenCesium() {
  Cesium.Ion.defaultAccessToken = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiJlNTg4MmJjZC0wZDZkLTQxODMtOGRhZi0wZWU2ZDI1ODY3ZGEiLCJpZCI6MzE4NTAsInNjb3BlcyI6WyJhc3IiLCJnYyJdLCJpYXQiOjE1OTYwNjMyMzV9.CnBln1kTTLjYJkCS1elia1_SoI6280GumVIJvq_q0VQ';
}

export function initViewerCesium(containerId) {

  const extent = Cesium.Rectangle.fromDegrees(-45, 50, -45, -90);
  Cesium.Camera.DEFAULT_VIEW_RECTANGLE = extent;
  Cesium.Camera.DEFAULT_VIEW_FACTOR = 0;

  const viewer = new Cesium.Viewer(containerId, {
    imageryProvider: new Cesium.OpenStreetMapImageryProvider({
      url: 'https://a.tile.openstreetmap.org/'
    }),
    FullscreenButton: false,
    navigationHelpButton: false,
    animation: false,
    timeline: false,
  });
  // viewer.fullscreenButton.container.style.visibility = 'hidden';
  return viewer;
}

// coord = [lat, lon], ex: [-19.88014, -43.90813]
export function addPointToMap(coordArr, name, text, viewerCesium) {
  const coord = {
    lat: coordArr[0],
    lon: coordArr[1]
  };
  const point = {
    name: name,
    // position : Cesium.Cartesian3.fromDegrees(-75.166493, 39.9060534),
    position: Cesium.Cartesian3.fromDegrees(coord.lon, coord.lat),
    point: {
      pixelSize: 5,
      color: Cesium.Color.RED,
      outlineColor: Cesium.Color.WHITE,
      outlineWidth: 2
    },
    label: {
      text: text,
      font: '14pt monospace',
      style: Cesium.LabelStyle.FILL_AND_OUTLINE,
      outlineWidth: 2,
      verticalOrigin: Cesium.VerticalOrigin.BOTTOM,
      pixelOffset: new Cesium.Cartesian2(0, -9)
    }
  };
  return viewerCesium.entities.add(point);
}

export function cameraFlyTo(coordArr, height, timeout) {
  const coord = {
    lat: coordArr[0],
    lon: coordArr[1]
  };

  setTimeout(() => {
    viewer.scene.view.camera.flyTo({
      destination: Cesium.Cartesian3.fromDegrees(coord.lon, coord.lat, height),
      orientation: {
        heading: Cesium.Math.toRadians(0.0),
        pitch: Cesium.Math.toRadians(-90.0),
        roll: 0.0
      }
    });
  }, timeout);
}

export function getCameraDegreesCoord(camera) {
  const currentCartesian = camera.position.clone();
  const currentCartographic = Cesium.Ellipsoid.WGS84.cartesianToCartographic(currentCartesian);
  const coord = {
    lat: Cesium.Math.toDegrees(currentCartographic.latitude),
    lon: Cesium.Math.toDegrees(currentCartographic.longitude),
    height: currentCartographic.height
  }
  return coord;
}

export function configCameraEvents(camera) {
  camera.moveStart.addEventListener(() => {
    console.log('moveStart', getCameraDegreesCoord(camera));
  });

  camera.moveEnd.addEventListener(() => {
    console.log('moveEnd', getCameraDegreesCoord(camera));
  });

  // viewer.scene.screenSpaceCameraController.inertiaSpin = 0;
  // viewer.scene.screenSpaceCameraController.inertiaTranslate = 0;
  // viewer.scene.screenSpaceCameraController.inertiaZoom = 0;
}
