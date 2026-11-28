function calculateCylinderVolume(radius, height) {
    if(radius < 0 || radius > 50 || height < 0 || height > 50) {
        return 'Invalid input! The radius and height should be between 0 and 50.';
    }

    var volume = Math.PI * Math.pow(radius, 2) * height;
    return volume;
}