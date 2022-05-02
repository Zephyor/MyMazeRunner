import React, { useState } from 'react';
import './MazeDashboard.css';
import MazeMap from './MazeMap';


const MazeDashboard = () => {
    
    const [selectedFiles, setSelectedFiles] = useState<string[]>([]);
 
    const handleFileChange = (event: any) => {
        const file = event.target.files[0];
        const reader = new FileReader();
        reader.onload = ((evt: ProgressEvent<FileReader>) => {
            if (evt.target?.result !== null) {
                setSelectedFiles([...selectedFiles, evt.target?.result as string]);
            }
        });
        reader.readAsText(file);
    }

    return (
        <div className='container'>
            <div className='file-selector'>
                <h1>Maze Runner Map</h1>
                <p>Default map / a_star solved map / brutforce</p>
            </div>
            <div className='card'>
                <div className='file-selector'>
                    <input type='file' onChange={handleFileChange}/>
                </div>
                <div className="maze-dashboard">
                    {selectedFiles.map((filename) => { 
                        return <MazeMap content={filename} />;
                     })}
                </div>
            </div>
        </div>
    );
}

export default MazeDashboard;